#include <iostream>
#include <queue>
#include <vector>

struct result {
  int len;
  std::vector<std::vector<std::pair<int, int>>> parents;
};

result bfs(int n, int start_x, int start_y, int end_x, int end_y) {
  std::vector<std::vector<bool>> used(n, std::vector<bool>(n, false));
  std::queue<std::pair<int, int>> queue;
  std::vector<std::vector<int>> dist(n, std::vector<int>(n, -1));
  std::vector<std::vector<std::pair<int, int>>> parents(
      n, std::vector<std::pair<int, int>>(n, std::make_pair(-1, -1)));

  queue.push({start_x, start_y});
  used[start_x][start_y] = true;
  dist[start_x][start_y] = 0;

  while (!queue.empty()) {
    auto vert = queue.front();
    queue.pop();

    std::pair<int, int> positions[] = {
        {vert.first - 1, vert.second + 2}, {vert.first + 1, vert.second + 2},
        {vert.first - 1, vert.second - 2}, {vert.first + 1, vert.second - 2},

        {vert.first - 2, vert.second + 1}, {vert.first + 2, vert.second + 1},
        {vert.first - 2, vert.second - 1}, {vert.first + 2, vert.second - 1}};

    for (auto &pair : positions) {
      if (pair.first < 0 || pair.first >= n || pair.second < 0 ||
          pair.second >= n || used[pair.first][pair.second]) {
        continue;
      }

      used[pair.first][pair.second] = true;
      queue.push(pair);
      dist[pair.first][pair.second] = dist[vert.first][vert.second] + 1;
      parents[pair.first][pair.second] = vert;
    }
  }

  return result{.len = dist[end_x][end_y], .parents = parents};
}

int main() {
  int n;
  std::cin >> n;

  int start_x, start_y, end_x, end_y;
  std::cin >> start_x >> start_y >> end_x >> end_y;

  auto result = bfs(n, --start_x, --start_y, --end_x, --end_y);
  std::cout << result.len << std::endl;

  std::vector<std::pair<int, int>> results;
  auto current = std::make_pair(end_x, end_y);

  while (current.first != -1) {
    results.push_back(current);
    current = result.parents[current.first][current.second];
  }

  for (int i = results.size() - 1; i >= 0; i--) {
    auto p = results[i];
    std::cout << ++p.first << " " << ++p.second << '\n';
  }

  return 0;
}
