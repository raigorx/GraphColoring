#include <array>
#include <exception>
#include <iostream>
#include <vector>

using std::array, std::vector, std::cout, std::endl;

namespace backtracking {

  static void printResult(const auto &result) {
    cout << "All possible colors combinations" << endl;
    for (const auto &nodes : result) {
      for (const auto &node : nodes) cout << node;
      cout << endl;
    }
  }

  //  return false If at least one neighbor node has same color
  static bool isValidColor(const auto neighbor,
                           const auto &graph,
                           const auto &coloredNodes,
                           const auto currentColor) {
    for (size_t node = 0; node < graph.size(); node++) {
      const bool isNeighbor = graph.at(neighbor).at(node) == 1;

      const bool hasSameColor = currentColor == coloredNodes.at(node);

      if (isNeighbor && hasSameColor) return false;
    }
    return true;
  }

  template <typename T, auto n_nodes>
  vector<T> graphColoring(const array<T, n_nodes> &graph,
                          const size_t nColors,
                          T coloredNodes = T(),
                          size_t currentNode = 0,
                          vector<T> result = vector<T>()) {
    //  base case
    if (currentNode == n_nodes) {
      result.push_back(coloredNodes);
      return result;
    }

    //  loop para busca un color valido para el nodo actual
    for (size_t currentColor = 1; currentColor <= nColors; currentColor++) {
      //  conditional for recursive case
      if (isValidColor(currentNode, graph, coloredNodes, currentColor)) {
        coloredNodes.at(currentNode) = currentColor;

        result = graphColoring(graph, nColors, coloredNodes, currentNode + 1, result);
      }
    }
    return result;
  }
}  //  namespace backtracking

namespace graphsMatrices {
  extern const array<array<size_t, 4>, 4> graph0 = {{
      {0, 1, 1, 1},
      {1, 0, 1, 0},
      {1, 1, 0, 1},
      {1, 0, 1, 0},
  }};
  extern const array<array<size_t, 6>, 6> graph1 = {{
      {0, 0, 1, 0, 1, 1},
      {0, 0, 0, 0, 1, 1},
      {1, 0, 0, 1, 1, 0},
      {0, 0, 1, 0, 0, 0},
      {1, 1, 1, 0, 0, 1},
      {1, 1, 0, 0, 1, 0},
  }};
}  //  namespace graphsMatrices

#ifndef _LIB
int main() {
  using backtracking::graphColoring, backtracking::printResult;
  using graphsMatrices::graph0, graphsMatrices::graph1;

  constexpr size_t nColors = 3;  //  Number of colors
  printResult(graphColoring(graph0, nColors));
  printResult(graphColoring(graph1, nColors));

  return EXIT_SUCCESS;
}
#endif  //  !_LIB

#ifdef _LIB
using T = array<size_t, 4>;
template vector<T> backtracking::graphColoring(
    const array<T, 4> &, const size_t, T, size_t, vector<T>);

using K = array<size_t, 6>;
template vector<K> backtracking::graphColoring(
    const array<K, 6> &, const size_t, K, size_t, vector<K>);
#endif  //  _LIB