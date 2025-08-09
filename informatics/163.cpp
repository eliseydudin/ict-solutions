#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using pos_t = std::pair<int, int>;

inline std::pair<int, int> chess_to_pos(char pos[3]) {
  return std::make_pair(pos[0] - 'a', pos[1] - '1');
}

std::vector<std::vector<int>> bfs(pos_t pos) {
  std::vector<std::vector<int>> used(8, std::vector<int>(8, -1));
  std::queue<pos_t> queue;
  queue.push(pos);
  used[pos.first][pos.second] = 0;

  while (!queue.empty()) {
    auto p = queue.front();
    queue.pop();

    std::pair<int, int> positions[] = {
        {p.first - 1, p.second + 2}, {p.first + 1, p.second + 2},
        {p.first - 1, p.second - 2}, {p.first + 1, p.second - 2},

        {p.first - 2, p.second + 1}, {p.first + 2, p.second + 1},
        {p.first - 2, p.second - 1}, {p.first + 2, p.second - 1}};

    for (auto &pair : positions) {
      if (pair.first < 0 || pair.first >= 8 || pair.second < 0 ||
          pair.second >= 8 || used[pair.first][pair.second] != -1) {
        continue;
      }

      used[pair.first][pair.second] = used[p.first][p.second] + 1;
      queue.push(pair);
    }
  }

  return used;
}

int main() {
  char pos1[3], pos2[3];
  std::cin >> pos1 >> pos2;

  auto used1 = bfs(chess_to_pos(pos1));
  auto used2 = bfs(chess_to_pos(pos2));
  int min_len = INT_MAX;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (used1[i][j] == -1 || used2[i][j] == -1 ||
          (used1[i][j] != used2[i][j]))
        continue;
      min_len = std::min(min_len, used1[i][j]);
    }
  }

  if (min_len != INT_MAX)
    std::cout << min_len << std::endl;
  else
    std::cout << -1 << std::endl;

  return 0;
}
