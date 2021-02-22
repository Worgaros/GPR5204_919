#pragma once
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

#include "maths/sphere.h"
#include "maths/aabb3.h"

namespace maths {

class Ray3 {
public:
	Ray3() = default;
	Ray3(Vector3f& origin, maths::Vector3f& direction) : origin_(origin), direction_(direction) {}

	struct HitInfo
	{
		HitInfo()
		{
			reset();
		}

		void reset()
		{
			distance = std::numeric_limits<float>::infinity();
			hit = false;
		}

		Vector3f hitPoint;
		Vector3f hitNormal;
		float distance;
		bool hit;

	};
	HitInfo info;

	Vector3f point_in_ray(float value) const {
		return { origin_ + direction_ * value };
	}

	Vector3f origin() const { return origin_; }
	Vector3f direction() const { return direction_; }
	Vector3f unit_direction() const { return unit_direction_; }

	bool intersect_sphere(HitInfo& info, Sphere& sphere);
	bool intersect_AABB3(HitInfo& info, AABB3 aabb);

private:
	Vector3f origin_ = {};
	Vector3f direction_ = {};
	Vector3f unit_direction_ = direction_.Normalized();
};

} // namespace maths