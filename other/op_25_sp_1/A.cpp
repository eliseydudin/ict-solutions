/*
 * Задача №5. Дейкстра
 */

#include <climits>
#include <iostream>
#include <vector>

void relax(std::vector<int> &dist, std::vector<std::vector<int>> &g, int i,
           int j) {
  if (dist[i] + g[i][j] < dist[j]) {
    dist[j] = dist[i] + g[i][j];
  }
}

int main() {
  int n, s, f;
  std::cin >> n >> s >> f;

  auto adjacent =
      std::vector<std::vector<int>>(n + 1, std::vector<int>(n + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> adjacent[i][j];
    }
  }

  std::vector<int> used(n + 1, 0), dist(n + 1, INT_MAX);
  dist[s] = 0;

  for (int i = 1; i < n; i++) {
    int min = INT_MAX, v = -1;

    for (int j = 1; j <= n; j++) {
      if (used[j] == 0 && dist[j] < min) {
        min = dist[j];
        v = j;
      }
    }

    if (v < 0) {
      break;
    }
    for (int j = 1; j <= n; j++) {
      if (used[j] == 0 && adjacent[v][j] != -1) {
        relax(dist, adjacent, v, j);
      }
    }

    used[v] = 1;
  }

  if (dist[f] == INT_MAX) {
    std::cout << "-1" << std::endl;
  } else {
    std::cout << dist[f] << std::endl;
  }

  return 0;
}
