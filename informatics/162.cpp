#include <iostream>
#include <queue>
#include <vector>

using matrix_t = std::vector<std::vector<int>>;
using pos_t = std::pair<int, int>;

int bfs(pos_t pos, matrix_t &mat, int n, int m) {
  if (mat[pos.first][pos.second] == 1) {
    return 0;
  }

  // also functions as a distance measurer
  std::vector<std::vector<int>> used(n, std::vector<int>(m, -1));
  std::queue<pos_t> queue;
  queue.push(pos);
  used[pos.first][pos.second] = 0;

  while (!queue.empty()) {
    auto vert = queue.front();
    queue.pop();

    pos_t positions[] = {{vert.first - 1, vert.second},
                         {vert.first + 1, vert.second},
                         {vert.first, vert.second - 1},
                         {vert.first, vert.second + 1}};

    for (auto pair : positions) {
      if (pair.first < 0 || pair.first >= n || pair.second < 0 ||
          pair.second >= m || used[pair.first][pair.second] != -1) {
        continue;
      }

      used[pair.first][pair.second] = used[vert.first][vert.second] + 1;
      if (mat[pair.first][pair.second] == 1) {
        return used[pair.first][pair.second];
      }

      queue.push(pair);
    }
  }

  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;

  matrix_t matrix(n, std::vector<int>(m, 0));
  for (auto &el : matrix) {
    for (auto &e : el) {
      std::cin >> e;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      auto pos = std::make_pair(i, j);
      std::cout << bfs(pos, matrix, n, m) << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
