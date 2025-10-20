#include <iostream>
#include <map>
#include <vector>

int room_size(int n, int x, int y, std::vector<std::vector<char>> &game_map,
              std::map<std::pair<int, int>, bool> &visited) {
  if (x < 0 || x >= n || y < 0 || y >= n || game_map[x][y] == '*' ||
      visited[{x, y}]) {
    return 0;
  }

  visited[{x, y}] = true;
  return 1 + room_size(n, x + 1, y, game_map, visited) +
         room_size(n, x - 1, y, game_map, visited) +
         room_size(n, x, y + 1, game_map, visited) +
         room_size(n, x, y - 1, game_map, visited);
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<char>> game_map(n, std::vector<char>(n, 0));
  for (auto &l : game_map)
    for (auto &el : l) std::cin >> el;

  std::map<std::pair<int, int>, bool> visited;
  int x, y;
  std::cin >> x >> y;

  std::cout << room_size(n, --x, --y, game_map, visited) << std::endl;

  return 0;
}
