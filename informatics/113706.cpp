// 20 points

#include <iostream>
#include <map>
#include <queue>
#include <vector>

// void debug_vector(std::vector<int> &vector) {
//   std::cout << "DEBUG: vector<int>{";
//   for (auto &el : vector) {
//     std::cout << ' ' << el << ",";
//   }
//   std::cout << " }" << std::endl;
// }

std::vector<int> bfs(int start, int finish,
                     std::vector<std::vector<bool>> &mat) {
  std::vector<bool> used(mat.size(), false);
  std::vector<int> parents(mat.size(), -1);
  std::queue<int> to_visit;

  to_visit.push(start);
  used[start] = true;

  while (!to_visit.empty()) {
    int vert = to_visit.front();
    to_visit.pop();

    for (int i = 0; i < mat.size(); i++) {
      if (!mat[vert][i] || used[i]) {
        continue;
      }

      used[i] = true;
      parents[i] = vert;
      to_visit.push(i);
    }
  }

  return parents;
}

int find_max_height(int i, int j, std::vector<std::vector<bool>> &graph,
                    std::vector<int> &heights,
                    std::map<int, std::vector<int>> &memo) {
  if (!memo.count(i)) {
    std::vector<bool> used(graph.size(), false);
    memo[i] = bfs(i, j, graph);
  }

  auto &parents = memo[i];

  if (parents[j] == -1) {
    return heights[i];
  }

  int finish = parents[j], max = heights[j];
  do {
    max = std::max(max, heights[finish]);
    finish = parents[finish];
  } while (finish != -1);

  return max;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> heights(n);
  std::vector<std::vector<bool>> graph(n, std::vector<bool>(n));
  std::map<int, std::vector<int>> memo;

  for (auto &el : heights) {
    std::cin >> el;
  }

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    std::cin >> a >> b;

    --a;
    --b;

    graph[a][b] = graph[b][a] = 1;
  }

  int k;
  std::cin >> k;
  std::string ch;

  for (int i = 0; i < k; i++) {
    int num1, num2;
    std::cin >> ch >> num1 >> num2;

    if (ch == "!") {
      heights[--num1] = num2;
    } else if (ch == "?") {
      std::cout << find_max_height(--num1, --num2, graph, heights, memo)
                << std::endl;
    }
  }

  return 0;
}
