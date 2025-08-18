#include <iostream>
#include <queue>
#include <vector>

struct cell_t {
  // up right down left
  bool direction[4] = {0};
  int dist = -1;
};

struct vert_t {
  std::pair<int, int> pos;
  int direction;
};

int bfs(int n, int m, std::vector<std::vector<bool>> &borders,
        std::pair<int, int> start, std::pair<int, int> finish) {
  std::vector<std::vector<cell_t>> used(n, std::vector<cell_t>(m));
  std::queue<vert_t> queue;

  queue.push({.pos = start, .direction = 0});
  queue.push({.pos = start, .direction = 1});
  queue.push({.pos = start, .direction = 2});
  queue.push({.pos = start, .direction = 3});

  used[start.first][start.second] = {.dist = 0};

  auto next_vertex = [&](vert_t v) {
    std::pair<int, int> offset;

    switch (v.direction) {
      case 0:
        offset = std::make_pair(v.pos.first - 1, v.pos.second);
        break;
      case 1:
        offset = std::make_pair(v.pos.first, v.pos.second + 1);
        break;
      case 2:
        offset = std::make_pair(v.pos.first + 1, v.pos.second);
        break;
      case 3:
        offset = std::make_pair(v.pos.first, v.pos.second - 1);
        break;
    }

    queue.push({.pos = offset, .direction = v.direction});
    used[offset.first][offset.second].dist =
        used[v.pos.first][v.pos.second].dist + 1;
  };

  while (!queue.empty()) {
    auto vert = queue.front();
    queue.pop();

    auto pos = vert.pos;

    if (pos.first < 0 || pos.first >= n || pos.second < 0 || pos.second >= m ||
        borders[pos.first][pos.second]) {
      continue;
    } else if (pos == finish) {
      return used[pos.first][pos.second].dist;
    }

    if (!used[pos.first][pos.second].direction[vert.direction]) {
      used[pos.first][pos.second].direction[vert.direction] = true;
      next_vertex(vert);
    }

    if (!used[pos.first][pos.second].direction[(vert.direction + 1) % 4]) {
      vert.direction = (vert.direction + 1) % 4;
      used[pos.first][pos.second].direction[vert.direction] = true;
      next_vertex(vert);
    }
  }

  std::abort();
}

int main() {
  int n, m;
  char _ignore;
  std::pair<int, int> start, finish;
  std::cin >> n >> m >> _ignore;
  // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  // std::cin.sync();

  std::vector<std::vector<bool>> borders(n, std::vector<bool>(m, false));

  for (int i = 0; i < n; i++) {
    std::string input;
    std::getline(std::cin, input);

    for (int j = 0; j < m; j++) {
      char s = input[j];

      if (s == 'X')
        borders[i][j] = true;
      else if (s == 'S')
        start = {i, j};
      else if (s == 'F')
        finish = {i, j};
    }
  }

  std::cout << bfs(n, m, borders, start, finish) << std::endl;

  return 0;
}
