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

#pragma once

#include <map>
#include <vector>
#include "maths/vector2.h"

namespace path {

	using NodeIndex = std::uint32_t;

	// This class is used to represent a node.
	class Node {
	public:
		Node() = default;
		Node(maths::Vector2f position, std::vector<NodeIndex> neighbors) {
			position_ = position;
			neighbors_ = neighbors;
		}

		// This function returns the neighbors of a node.
		const std::vector<NodeIndex>& neighbors() const {
			return neighbors_;
		}

		// This function returns the position of a node.
		const maths::Vector2f position() const {
			return position_;
		}

		Node& operator=(Node node) {
			position_ = node.position_;
			neighbors_ = node.neighbors_;
			return *this;
		}
	private:
		std::vector<NodeIndex> neighbors_;
		maths::Vector2f position_;
	};

	// This class is used to represent a map.
	class Map {
	public:
		Map() = default;
		// This function push a node in graph_. // take ownership
		void AddNode(Node&& node) {
			graph_.emplace_back(node);
		}
		// This function find the lowest cost path with A* from the start node to the last node.
		std::vector<NodeIndex> FindPath(NodeIndex start_node, NodeIndex end_node);
		void Reset() {
			graph_.clear();
			path_.clear();
			came_from_.clear();
			cost_so_far_.clear();
		}
	private:
		std::vector<Node> graph_;
		std::vector<NodeIndex> path_;
	};

}  // namespace path
