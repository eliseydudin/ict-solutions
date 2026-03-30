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
  int n, start, finish;
  std::cin >> n >> start >> finish;

  std::vector<int> dist(n, -1);
  std::vector<std::vector<int>> matrix(n, std::vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> matrix[i][j];
    }
  }

  solve(n, dist, matrix, --start, --finish);
  std::cout << dist[finish] << std::endl;

  return 0;
}
