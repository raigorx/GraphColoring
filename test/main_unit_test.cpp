#include <gtest/gtest.h>

#include "../include/lib.hpp"

TEST(graphColoring, graph0) {
  using backtracking::graphColoring;
  using graphsMatrices::graph0;
  using std::array, std::vector;

  constexpr size_t nColors = 3;
  const vector<array<size_t, graph0.size()>> graph0Result = {{
      {1, 2, 3, 2},
      {1, 3, 2, 3},
      {2, 1, 3, 1},
      {2, 3, 1, 3},
      {3, 1, 2, 1},
      {3, 2, 1, 2},
  }};
  EXPECT_EQ(graphColoring(graph0, nColors), graph0Result);
}

TEST(graphColoring, graph1) {
  using backtracking::graphColoring;
  using graphsMatrices::graph1;
  using std::array, std::vector;

  constexpr size_t nColors = 3;
  const vector<array<size_t, graph1.size()>> graph1Result = {{
      {1, 1, 2, 1, 3, 2},
      {1, 1, 2, 3, 3, 2},
      {1, 1, 3, 1, 2, 3},
      {1, 1, 3, 2, 2, 3},
      {2, 2, 1, 2, 3, 1},
      {2, 2, 1, 3, 3, 1},
      {2, 2, 3, 1, 1, 3},
      {2, 2, 3, 2, 1, 3},
      {3, 3, 1, 2, 2, 1},
      {3, 3, 1, 3, 2, 1},
      {3, 3, 2, 1, 1, 2},
      {3, 3, 2, 3, 1, 2},
  }};
  EXPECT_EQ(graphColoring(graph1, nColors), graph1Result);
}