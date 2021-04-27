#include <benchmark/benchmark.h>
#include "paths/path.h"

static void BM_Path(benchmark::State& state) {
    // Perform setup here
	path::Node node0(maths::Vector2f(0.0f, 0.0f), { 1, 14 });//A - 0
	path::Node node1(maths::Vector2f(2.0f, 1.0f), { 0, 14, 15, 26 });//B - 1
	path::Node node2(maths::Vector2f(4.0f, 2.0f), { 3, 15, 16, 17 });//C - 2
	path::Node node3(maths::Vector2f(4.0f, 0.0f), { 2, 7, 17, 25, 26 });//D - 3
	path::Node node4(maths::Vector2f(5.0f, -1.0f), { 24, 25, 27 });//E - 4
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
	path::Map map;
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
	 // This code gets timed
    for (auto _ : state) {
		// Find the lowest cost path.
		benchmark::DoNotOptimize(map.FindPath(0, 22));
    }
}

static void BM_OptiPath(benchmark::State& state) {
	// Perform setup here
	path2::Node node0(maths::Vector2f(0.0f, 0.0f), { 1, 14 });//A - 0
	path2::Node node1(maths::Vector2f(2.0f, 1.0f), { 0, 14, 15, 26 });//B - 1
	path2::Node node2(maths::Vector2f(4.0f, 2.0f), { 3, 15, 16, 17 });//C - 2
	path2::Node node3(maths::Vector2f(4.0f, 0.0f), { 2, 7, 17, 25, 26 });//D - 3
	path2::Node node4(maths::Vector2f(5.0f, -1.0f), { 24, 25, 27 });//E - 4
	path2::Node node5(maths::Vector2f(7.0f, -2.0f), { 12, 19, 27, 28 });//F - 5
	path2::Node node6(maths::Vector2f(7.0f, 0.0f), { 8, 11, 13, 18 });//G - 6
	path2::Node node7(maths::Vector2f(3.0f, -2.0f), { 3, 14, 25 });//H - 7
	path2::Node node8(maths::Vector2f(8.0f, 1.0f), { 6, 9, 11, 20 });//I - 8
	path2::Node node9(maths::Vector2f(9.0f, 2.0f), { 8, 10, 20, 22 });//J - 9
	path2::Node node10(maths::Vector2f(7.0f, 3.0f), { 9, 16 });//K - 10
	path2::Node node11(maths::Vector2f(6.0f, 1.0f), { 6, 8, 16, 17 });//L - 11
	path2::Node node12(maths::Vector2f(5.0f, -3.0f), { 5, 24, 28 });//M - 12
	path2::Node node13(maths::Vector2f(9.0f, -1.0f), { 6, 18, 20 });//N - 13
	path2::Node node14(maths::Vector2f(2.0f, -1.0f), { 0, 1, 7, 26 });//O - 14
	path2::Node node15(maths::Vector2f(3.0f, 2.0f), { 1, 2 });//P - 15
	path2::Node node16(maths::Vector2f(6.0f, 2.0f), { 2, 10, 11 });//Q - 16
	path2::Node node17(maths::Vector2f(5.0f, 1.0f), { 2, 3, 11, 27 });//R - 17
	path2::Node node18(maths::Vector2f(7.0f, -1.0f), { 6, 13, 19, 27 });//S - 18
	path2::Node node19(maths::Vector2f(8.0f, -2.0f), { 5, 18, 23, 29 });//T - 19
	path2::Node node20(maths::Vector2f(10.0f, 0.0f), { 8, 9, 13, 21 });//U - 20
	path2::Node node21(maths::Vector2f(11.0f, 1.0f), { 20, 22 });//V - 21
	path2::Node node22(maths::Vector2f(11.0f, 2.0f), { 9, 21 });//W - 22
	path2::Node node23(maths::Vector2f(9.0f, -3.0f), { 19, 29 });//Z - 23
	path2::Node node24(maths::Vector2f(5.0f, -2.0f), { 4, 12 });//A1 - 24
	path2::Node node25(maths::Vector2f(4.0f, -1.0f), { 3, 4, 7 });//B1 - 25
	path2::Node node26(maths::Vector2f(3.0f, 0.0f), { 1, 3, 14 });//C1 - 26
	path2::Node node27(maths::Vector2f(6.0f, -1.0f), { 4, 5, 17, 18 });//D1 - 27
	path2::Node node28(maths::Vector2f(7.0f, -3.0f), { 5, 12, 29 });//E1 - 28
	path2::Node node29(maths::Vector2f(8.0f, -3.0f), { 19, 23, 28 });//F1 - 29
	path2::Map map;
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
	// This code gets timed
	for (auto _ : state) {
		// Find the lowest cost path.
		benchmark::DoNotOptimize(map.FindPath(0, 22));
	}
}

// Register the function as a benchmark
BENCHMARK(BM_Path);
BENCHMARK(BM_OptiPath);
// Run the benchmark
BENCHMARK_MAIN();