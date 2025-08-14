#include <iostream>
#include <queue>
#include <vector>

using pos_t = std::pair<int, int>;
using matrix_t = std::vector<std::vector<int>>;

inline bool out_of_bounds(pos_t pos, int n, int m) {
  return pos.first < 0 || pos.first >= n || pos.second < 0 || pos.second >= m;
}

int bfs(int n, int m, matrix_t &mat) {
  std::queue<pos_t> queue;
  matrix_t used(n, std::vector<int>(m, -1));

  used[0][0] = 0;
  queue.push(std::make_pair(0, 0));

  while (!queue.empty()) {
    auto vert = queue.front();
    queue.pop();

    pos_t directions[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (auto dir : directions) {
      pos_t new_dir = {vert.first + dir.first, vert.second + dir.second};

      if (out_of_bounds(new_dir, n, m) ||
          mat[new_dir.first][new_dir.second] == 1) {
        continue;
      }

      while (!out_of_bounds(new_dir, n, m) &&
             mat[new_dir.first][new_dir.second] != 1) {
        if (mat[new_dir.first][new_dir.second] == 2) {
          return used[vert.first][vert.second] + 1;
        }

        new_dir.first += dir.first;
        new_dir.second += dir.second;
      }

      new_dir.first -= dir.first;
      new_dir.second -= dir.second;

      if (used[new_dir.first][new_dir.second] != -1) {
        continue;
      }

      queue.push(new_dir);
      used[new_dir.first][new_dir.second] = used[vert.first][vert.second] + 1;
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

  std::cout << bfs(n, m, matrix) << std::endl;

  return 0;
}
