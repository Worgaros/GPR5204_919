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

#include <gtest/gtest.h>
#include "paths/path.h"

namespace path {


	TEST(Astar, Map_FindPath) {
		// A test with 2 nodes and 1 path.
		// Create node0.
		Node node0(maths::Vector2f(0.0f, 0.0f), { 1 });
		// Create node1.
		Node node1(maths::Vector2f(1.0f, 0.0f), { 0 });
		// Instantiate map.
		Map map;
		// Create expected path.
		std::vector<NodeIndex> expected_path{ 0, 1 };
		// Add node0 in graph.
		map.AddNode(std::move(node0));
		// Add node1 in graph.
		map.AddNode(std::move(node1));
		// Find the lowest cost path.
		std::vector<NodeIndex> path = map.FindPath(0, 1);
		// Check if the path is the same as the expected path.
		EXPECT_TRUE(std::equal(path.begin(), path.end(), expected_path.begin()));
		// Reverse the expected path.
		std::reverse(expected_path.begin(), expected_path.end());
		// Check if the path is not the same as the expected path.
		EXPECT_FALSE(std::equal(path.begin(), path.end(), expected_path.begin()));

		// A test with 5 nodes and 2 path going into 1 path.
		map.ClearGraph();
		node0 = Node(maths::Vector2f(0.0f, 0.0f), { 1, 3 });
		node1 = Node(maths::Vector2f(2.0f, 2.0f), { 0, 2 });
		Node node2(maths::Vector2f(5.0f, 2.0f), { 1, 3, 4 });
		Node node3(maths::Vector2f(4.0f, -2.0f), { 0, 2 });
		Node node4(maths::Vector2f(8.0f, 0.0f), { 2 });
		expected_path = { 0, 1, 2, 4 };

		map.AddNode(std::move(node0));
		map.AddNode(std::move(node1));
		map.AddNode(std::move(node2));
		map.AddNode(std::move(node3));
		map.AddNode(std::move(node4));
		path = map.FindPath(0, 4);
		EXPECT_TRUE(std::equal(path.begin(), path.end(), expected_path.begin()));
		std::reverse(expected_path.begin(), expected_path.end());
		EXPECT_FALSE(std::equal(path.begin(), path.end(), expected_path.begin()));

		// A test with 5 node and 2 path.
		map.ClearGraph();
		node0 = Node(maths::Vector2f(0.0f, 0.0f), { 1, 3 });
		node1 = Node(maths::Vector2f(0.5f, 1.0f), { 0, 2 });
		node2 = Node(maths::Vector2f(1.5f, 1.0f), { 1, 4 });
		node3 = Node(maths::Vector2f(1.0f, -1.0f), { 0, 4 });
		node4 = Node(maths::Vector2f(2.0f, 0.0f), { 2, 3 });
		expected_path = { 0, 3, 4 };
		map.AddNode(std::move(node0));
		map.AddNode(std::move(node1));
		map.AddNode(std::move(node2));
		map.AddNode(std::move(node3));
		map.AddNode(std::move(node4));
		path = map.FindPath(0, 4);
		EXPECT_TRUE(std::equal(path.begin(), path.end(), expected_path.begin()));
		std::reverse(expected_path.begin(), expected_path.end());
		EXPECT_FALSE(std::equal(path.begin(), path.end(), expected_path.begin()));

		// A test with 5 nodes and 0 path.
		map.ClearGraph();
		node0 = Node(maths::Vector2f(0.0f, 0.0f), { 1, 2 });
		node1 = Node(maths::Vector2f(3.0f, 2.0f), { 0, 2 });
		node2 = Node(maths::Vector2f(4.0f, -1.0f), { 0, 1, 3 });
		node3 = Node(maths::Vector2f(5.0f, 2.0f), { 3 });
		node4 = Node(maths::Vector2f(8.0f, 1.0f), {});
		std::vector<NodeIndex> empty_path;
		map.AddNode(std::move(node0));
		map.AddNode(std::move(node1));
		map.AddNode(std::move(node2));
		map.AddNode(std::move(node3));
		map.AddNode(std::move(node4));
		path = map.FindPath(0, 4);
		EXPECT_TRUE(std::equal(path.begin(), path.end(), empty_path.begin()));

		//map2
		map.ClearGraph();
		node0 = Node(maths::Vector2f(0.0f, 0.0f), { 1, 14 });//A - 0
		node1 = Node(maths::Vector2f(2.0f, 1.0f), { 0, 14, 15, 26 });//B - 1
		node2 = Node(maths::Vector2f(4.0f, 2.0f), { 3, 15, 16, 17 });//C - 2
		node3 = Node(maths::Vector2f(4.0f, 0.0f), { 2, 7, 17, 25, 26 });//D - 3
		node4 = Node(maths::Vector2f(5.0f, -1.0f), { 24, 25, 27 });//E - 4
		path::Node node5(maths::Vector2f(7.0f, -2.0f), { 12, 19, 27, 28 });//F - 5
		path::Node node6(maths::Vector2f(7.0f, 0.0f), { 8, 11, 13, 18 });//G - 6
		path::Node node7(maths::Vector2f(3.0f, -2.0f), { 3, 14, 25 });//H - 7
		path::Node node8(maths::Vector2f(8.0f, 1.0f), { 6, 9, 11, 20 });//I - 8
		path::Node node9(maths::Vector2f(9.0f, 2.0f), { 8, 10, 20, 22 });//J - 9
		path::Node node10(maths::Vector2f(7.0f, 3.0f), { 9, 16 });//K - 10
		path::Node node11(maths::Vector2f(6.0f, 1.0f), { 6, 8, 16, 17 });//L - 11
		path::Node node12(maths::Vector2f(5.0f, -3.0f), { 5, 24, 28 });//M - 12
		path::Node node13(maths::Vector2f(9.0f, -1.0f), { 6, 18, 20 });//N - 13
		path::Node node14(maths::Vector2f(2.0f, -1.0f), { 0, 1, 7, 26 });//O - 14
		path::Node node15(maths::Vector2f(3.0f, 2.0f), { 1, 2 });//P - 15
		path::Node node16(maths::Vector2f(6.0f, 2.0f), { 2, 10, 11 });//Q - 16
		path::Node node17(maths::Vector2f(5.0f, 1.0f), { 2, 3, 11, 27 });//R - 17
		path::Node node18(maths::Vector2f(7.0f, -1.0f), { 6, 13, 19, 27 });//S - 18
		path::Node node19(maths::Vector2f(8.0f, -2.0f), { 5, 18, 23, 29 });//T - 19
		path::Node node20(maths::Vector2f(10.0f, 0.0f), { 8, 9, 13, 21 });//U - 20
		path::Node node21(maths::Vector2f(11.0f, 1.0f), { 20, 22 });//V - 21
		path::Node node22(maths::Vector2f(11.0f, 2.0f), { 9, 21 });//W - 22
		path::Node node23(maths::Vector2f(9.0f, -3.0f), { 19, 29 });//Z - 23
		path::Node node24(maths::Vector2f(5.0f, -2.0f), { 4, 12 });//A1 - 24
		path::Node node25(maths::Vector2f(4.0f, -1.0f), { 3, 4, 7 });//B1 - 25
		path::Node node26(maths::Vector2f(3.0f, 0.0f), { 1, 3, 14 });//C1 - 26
		path::Node node27(maths::Vector2f(6.0f, -1.0f), { 4, 5, 17, 18 });//D1 - 27
		path::Node node28(maths::Vector2f(7.0f, -3.0f), { 5, 12, 29 });//E1 - 28
		path::Node node29(maths::Vector2f(8.0f, -3.0f), { 19, 23, 28 });//F1 - 29
		map.AddNode(std::move(node0));
		map.AddNode(std::move(node1));
		map.AddNode(std::move(node2));
		map.AddNode(std::move(node3));
		map.AddNode(std::move(node4));
		map.AddNode(std::move(node5));
		map.AddNode(std::move(node6));
		map.AddNode(std::move(node7));
		map.AddNode(std::move(node8));
		map.AddNode(std::move(node9));
		map.AddNode(std::move(node10));
		map.AddNode(std::move(node11));
		map.AddNode(std::move(node12));
		map.AddNode(std::move(node13));
		map.AddNode(std::move(node14));
		map.AddNode(std::move(node15));
		map.AddNode(std::move(node16));
		map.AddNode(std::move(node17));
		map.AddNode(std::move(node18));
		map.AddNode(std::move(node19));
		map.AddNode(std::move(node20));
		map.AddNode(std::move(node21));
		map.AddNode(std::move(node22));
		map.AddNode(std::move(node23));
		map.AddNode(std::move(node24));
		map.AddNode(std::move(node25));
		map.AddNode(std::move(node26));
		map.AddNode(std::move(node27));
		map.AddNode(std::move(node28));
		map.AddNode(std::move(node29));
		
		path2::Node onode0(maths::Vector2f(0.0f, 0.0f), { 1, 14 });//A - 0
		path2::Node onode1(maths::Vector2f(2.0f, 1.0f), { 0, 14, 15, 26 });//B - 1
		path2::Node onode2(maths::Vector2f(4.0f, 2.0f), { 3, 15, 16, 17 });//C - 2
		path2::Node onode3(maths::Vector2f(4.0f, 0.0f), { 2, 7, 17, 25, 26 });//D - 3
		path2::Node onode4(maths::Vector2f(5.0f, -1.0f), { 24, 25, 27 });//E - 4
		path2::Node onode5(maths::Vector2f(7.0f, -2.0f), { 12, 19, 27, 28 });//F - 5
		path2::Node onode6(maths::Vector2f(7.0f, 0.0f), { 8, 11, 13, 18 });//G - 6
		path2::Node onode7(maths::Vector2f(3.0f, -2.0f), { 3, 14, 25 });//H - 7
		path2::Node onode8(maths::Vector2f(8.0f, 1.0f), { 6, 9, 11, 20 });//I - 8
		path2::Node onode9(maths::Vector2f(9.0f, 2.0f), { 8, 10, 20, 22 });//J - 9
		path2::Node onode10(maths::Vector2f(7.0f, 3.0f), { 9, 16 });//K - 10
		path2::Node onode11(maths::Vector2f(6.0f, 1.0f), { 6, 8, 16, 17 });//L - 11
		path2::Node onode12(maths::Vector2f(5.0f, -3.0f), { 5, 24, 28 });//M - 12
		path2::Node onode13(maths::Vector2f(9.0f, -1.0f), { 6, 18, 20 });//N - 13
		path2::Node onode14(maths::Vector2f(2.0f, -1.0f), { 0, 1, 7, 26 });//O - 14
		path2::Node onode15(maths::Vector2f(3.0f, 2.0f), { 1, 2 });//P - 15
		path2::Node onode16(maths::Vector2f(6.0f, 2.0f), { 2, 10, 11 });//Q - 16
		path2::Node onode17(maths::Vector2f(5.0f, 1.0f), { 2, 3, 11, 27 });//R - 17
		path2::Node onode18(maths::Vector2f(7.0f, -1.0f), { 6, 13, 19, 27 });//S - 18
		path2::Node onode19(maths::Vector2f(8.0f, -2.0f), { 5, 18, 23, 29 });//T - 19
		path2::Node onode20(maths::Vector2f(10.0f, 0.0f), { 8, 9, 13, 21 });//U - 20
		path2::Node onode21(maths::Vector2f(11.0f, 1.0f), { 20, 22 });//V - 21
		path2::Node onode22(maths::Vector2f(11.0f, 2.0f), { 9, 21 });//W - 22
		path2::Node onode23(maths::Vector2f(9.0f, -3.0f), { 19, 29 });//Z - 23
		path2::Node onode24(maths::Vector2f(5.0f, -2.0f), { 4, 12 });//A1 - 24
		path2::Node onode25(maths::Vector2f(4.0f, -1.0f), { 3, 4, 7 });//B1 - 25
		path2::Node onode26(maths::Vector2f(3.0f, 0.0f), { 1, 3, 14 });//C1 - 26
		path2::Node onode27(maths::Vector2f(6.0f, -1.0f), { 4, 5, 17, 18 });//D1 - 27
		path2::Node onode28(maths::Vector2f(7.0f, -3.0f), { 5, 12, 29 });//E1 - 28
		path2::Node onode29(maths::Vector2f(8.0f, -3.0f), { 19, 23, 28 });//F1 - 29
		path2::Map map2;
		map2.AddNode(std::move(onode0));
		map2.AddNode(std::move(onode1));
		map2.AddNode(std::move(onode2));
		map2.AddNode(std::move(onode3));
		map2.AddNode(std::move(onode4));
		map2.AddNode(std::move(onode5));
		map2.AddNode(std::move(onode6));
		map2.AddNode(std::move(onode7));
		map2.AddNode(std::move(onode8));
		map2.AddNode(std::move(onode9));
		map2.AddNode(std::move(onode10));
		map2.AddNode(std::move(onode11));
		map2.AddNode(std::move(onode12));
		map2.AddNode(std::move(onode13));
		map2.AddNode(std::move(onode14));
		map2.AddNode(std::move(onode15));
		map2.AddNode(std::move(onode16));
		map2.AddNode(std::move(onode17));
		map2.AddNode(std::move(onode18));
		map2.AddNode(std::move(onode19));
		map2.AddNode(std::move(onode20));
		map2.AddNode(std::move(onode21));
		map2.AddNode(std::move(onode22));
		map2.AddNode(std::move(onode23));
		map2.AddNode(std::move(onode24));
		map2.AddNode(std::move(onode25));
		map2.AddNode(std::move(onode26));
		map2.AddNode(std::move(onode27));
		map2.AddNode(std::move(onode28));
		map2.AddNode(std::move(onode29));
		path = map.FindPath(0, 22);
		auto path2 = map2.FindPath(0, 22);
		EXPECT_TRUE(std::equal(path.begin(), path.end(), path2.begin()));
	}

	TEST(Astar, Astar_PriorityQueue) {
		// Check if the queue is empty.
		Map::InvertedPriorityQueue queue;
		EXPECT_TRUE(queue.empty());

		// A test to put an element in the queue.
		NodeIndex node_index = 1;
		NodeIndex node_index_2 = 2;
		float priority = 2.0f;
		float priority_2 = 1.0f;
		queue.emplace(node_index, priority);
		EXPECT_TRUE(queue.top().first == node_index);
		queue.emplace(node_index, priority);
		EXPECT_FALSE(queue.top().first == node_index_2);

		// A test to get the lowest element.
		queue.emplace(node_index, priority);
		queue.emplace(node_index_2, priority_2);
		EXPECT_TRUE(queue.top().first == node_index_2);
	}

}  // namespace astar
