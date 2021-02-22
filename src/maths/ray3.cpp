/*
MIT License

Copyright (c) 2021 SAE Institute Geneva

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "maths/ray3.h"

namespace maths {

	bool Ray3::intersect_sphere(HitInfo& info, Sphere& sphere) {
		
		Vector3f v = sphere.center() - origin_;
		float d = v.Dot(unit_direction_);
		if (d < 0)
		{
			return false;
		}

		float squaredDistance = v.Dot(v) - (d * d);
		float radius2 = sphere.radius() * sphere.radius();
		if (squaredDistance > radius2)
		{
			return false;
		}

		auto q = std::sqrt(radius2 - squaredDistance);

		auto t0 = d + q;
		auto t1 = d - q;

		bool hasHit = false;
		float dis;
		if (t0 >= 0) {
			dis = t0;
			hasHit = true;
		}

		if (t1 >= 0) {
			if (!hasHit || t1 < dis) {
				dis = t1;
				hasHit = true;
			}
		}

		if (!hasHit) {
			return false;
		}

		auto pt = origin_ + unit_direction_ * dis;
		info.hit = true;
		info.hitPoint = pt;
		info.distance = dis;

		return true;
	}

	bool Ray3::intersect_AABB3(HitInfo& info, AABB3 aabb) {
		
		Vector3f lb = aabb.bottom_left();
		Vector3f rt = aabb.top_right();
		Vector3f dirfrac;

		dirfrac.x = 1.0f / unit_direction().x;
		dirfrac.y = 1.0f / unit_direction().y;
		dirfrac.z = 1.0f / unit_direction().z;
		// lb is the corner of AABB with minimal coordinates - left bottom, rt is maximal corner
		float t1 = (lb.x - origin_.x) * dirfrac.x;
		float t2 = (rt.x - origin_.x) * dirfrac.x;
		float t3 = (lb.y - origin_.y) * dirfrac.y;
		float t4 = (rt.y - origin_.y) * dirfrac.y;
		float t5 = (lb.z - origin_.z) * dirfrac.z;
		float t6 = (rt.z - origin_.z) * dirfrac.z;

		float tmin = std::max(std::max(std::min(t1, t2), std::min(t3, t4)), std::min(t5, t6));
		float tmax = std::min(std::min(std::max(t1, t2), std::max(t3, t4)), std::max(t5, t6));

		// if tmax < 0, ray (line) is intersecting AABB, but the whole AABB is behind us
		if (tmax < 0)
		{
			info.distance = tmax;
			return false;
		}

		// if tmin > tmax, ray doesn't intersect AABB
		if (tmin > tmax)
		{
			info.distance = tmax;
			return false;
		}

		info.distance = tmin;
		info.hitPoint = origin_ + direction_ * info.distance;
		return true;
	}
	
} // namespace maths