#include <climits>
#include <iostream>
#include <set>
#include <vector>

void solve(int n, std::vector<int>& dist, std::vector<std::vector<int>>& matrix,
           int start, int finish) {
  std::set<int> visited;
  int target = start;
  dist[target] = 0;

  while (true) {
    for (int i = 0; i < n; i++) {
      auto distance_to = matrix[target][i];
      if (distance_to == 0 || distance_to == -1 || visited.count(i) == 1)
        continue;

      int new_dist = dist[target] + distance_to;
      if (new_dist < dist[i] || dist[i] == -1) dist[i] = new_dist;
    }

    visited.insert(target);
    target = INT_MAX;
    for (int i = 0; i < n; i++) {
      auto d = dist[i];
      if (visited.count(i) == 1 || d == -1) continue;
      if (target == INT_MAX || dist[target] > d) target = i;
    }

    if (target == INT_MAX) {
      break;
    }
  }
}

int main() {
  int n, paths, l, r;
  std::cin >> n;

  std::vector<int> dist(n, -1), prices(n);
  std::vector<std::vector<int>> matrix(n, std::vector<int>(n, -1));

  for (auto& el : prices) std::cin >> el;
  std::cin >> paths;

  for (int i = 0; i < paths; i++) {
    std::cin >> l >> r;
    l -= 1;
    r -= 1;

    matrix[l][r] = prices[l];
    matrix[r][l] = prices[r];
  }

  solve(n, dist, matrix, 0, n - 1);
  std::cout << dist[n - 1] << std::endl;

  return 0;
}
