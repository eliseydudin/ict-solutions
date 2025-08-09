#include <iostream>
#include <queue>

std::vector<int> bfs(int start, int finish, std::vector<std::vector<int>> &mat,
                     int &res) {
  std::vector<bool> used(mat.size(), false);
  std::vector<int> dist(mat.size(), -1), parents(mat.size(), -1);
  std::queue<int> to_visit;

  to_visit.push(start);
  used[start] = true;
  dist[start] = 0;

  while (!to_visit.empty()) {
    int vert = to_visit.front();
    to_visit.pop();

    for (int i = 0; i < mat.size(); i++) {
      if (!mat[vert][i] || used[i]) {
        continue;
      }

      used[i] = true;
      dist[i] = dist[vert] + 1;
      parents[i] = vert;
      to_visit.push(i);
    }
  }

  res = dist[finish];
  return parents;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) std::cin >> matrix[i][j];
  }

  int start, finish, res;
  std::cin >> start >> finish;

  std::vector<int> parents = bfs(--start, --finish, matrix, res), results;
  if (res == -1) {
    std::cout << -1 << std::endl;
    return 0;
  } else if (res == 0) {
    std::cout << 0 << std::endl;
    return 0;
  }

  std::cout << res << std::endl;

  while (finish != -1) {
    results.push_back(finish + 1);
    finish = parents[finish];
  }

  for (int i = results.size() - 1; i >= 0; i--) {
    std::cout << results[i] << ' ';
  }
  std::cout << '\n';

  return 0;
}
