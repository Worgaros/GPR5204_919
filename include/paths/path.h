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
#include <queue>
#include <vector>
#include <array> 
#include "maths/vector2.h"

namespace path {

	using NodeIndex = std::uint32_t;
	constexpr std::size_t INVALID_NODE_INDEX = std::numeric_limits<NodeIndex>::max();

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
		using NodePair = std::pair<NodeIndex, float>;
		struct NodePairCompare
		{
			bool operator() (const NodePair& n1, const NodePair& n2) const { return n1.second > n2.second; }
		};
		using InvertedPriorityQueue = std::priority_queue<
			NodePair,
			std::vector<NodePair>,
			NodePairCompare>;
		Map() = default;
		// This function push a node in graph_. // take ownership
		void AddNode(Node&& node) {
			graph_.emplace_back(node);
		}
		void ClearGraph() {
			graph_.clear();
		}
		// This function find the lowest cost path with A* from the start node to the last node.
		std::vector<NodeIndex> FindPath(NodeIndex start_node, NodeIndex end_node);
	private:
		std::vector<Node> graph_;
		std::vector<NodeIndex> path_;
	};
	

	 

}  // namespace path

namespace path2
{
	using NodeIndex = std::uint8_t; //256 nodes max
	constexpr auto INVALID_NODE_INDEX = std::numeric_limits<NodeIndex>::max();

	// This class is used to represent a node.
	class Node {
	public:

		static constexpr std::size_t MAX_NEIGHBOR_NMB = 8;
		Node() = default;
		Node(maths::Vector2f position, std::initializer_list<NodeIndex> neighbors) {
			position_ = position;
			neighbors_.fill(INVALID_NODE_INDEX);
			std::copy(neighbors.begin(), neighbors.end(), neighbors_.begin());
		}

		// This function returns the neighbors of a node.
		const auto& neighbors() const {
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
		std::array < NodeIndex, MAX_NEIGHBOR_NMB > neighbors_;
		maths::Vector2f position_;
	};

	// This class is used to represent a map.
	class Map {
	public:
		using NodePair = std::pair<NodeIndex, float>;
		struct NodePairCompare
		{
			bool operator() (const NodePair& n1, const NodePair& n2) const { return n1.second > n2.second; }
		};
		using InvertedPriorityQueue = std::priority_queue<
			NodePair,
			std::vector<NodePair>,
			NodePairCompare>;
		Map() = default;
		// This function push a node in graph_. // take ownership
		void AddNode(Node&& node) {
			graph_.emplace_back(node);
		}
		void ClearGraph() {
			graph_.clear();
		}
		// This function find the lowest cost path with A* from the start node to the last node.
		std::vector<NodeIndex> FindPath(NodeIndex start_node, NodeIndex end_node);
	private:
		std::vector<Node> graph_;
		std::vector<NodeIndex> path_;
		// The node with the lowest cost to go to the key node.
		std::vector<NodeIndex> came_from_;
		// The lowest cost to go to a node.
		std::vector<float> cost_so_far_;
	};


}
