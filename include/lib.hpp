#pragma once

#include <array>
#include <exception>
#include <iostream>
#include <vector>

namespace backtracking {
  using std::array, std::vector;

  void printResult(const auto &);
  bool isValidColor(auto, const auto &, const auto &, auto);

  //template <typename T, auto n_nodes>
  //vector<T> graphColoring(
  //    const array<T, n_nodes> &, const size_t, T, size_t, vector<T>);
  template <typename T, auto n_nodes>
  vector<T> graphColoring(
      const array<T, n_nodes> &, const size_t, T = T(), size_t = 0, vector<T> = vector<T>());
  //vector<T> graphColoring(
  //    const array<T, n_nodes> &, const size_t, T, size_t, vector<T>);
}  //  namespace backtracking

namespace graphsMatrices {
  using std::array;
  extern const array<array<size_t, 4>, 4> graph0;
  extern const array<array<size_t, 6>, 6> graph1;
}  //  namespace graphsMatrices