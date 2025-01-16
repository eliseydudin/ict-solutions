/* TODO */

#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

typedef int32_t i32;
typedef int8_t i8;

struct pos {
  i8 x, y;

  pos(std::string p) {
    this->x = p[0] - 'a';
    this->y = p[1] - 1 - '0';
  }

  pos(i8 x, i8 y) {
    this->x = x;
    this->y = y;
  }

  bool operator==(pos other) {
    return this->x == other.x && this->y == other.y;
  }
};

const std::vector<pos> directions = {{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                                     {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

bool is_valid(i32 x, i32 y) { return x >= 0 && x < 8 && y >= 0 && y < 8; }

i32 solve_for_king(pos start, pos target) {
  if (start == target) return 0;

  std::queue<pos> q;
  std::vector<std::vector<bool>> visited(8, std::vector<bool>(8, false));
  std::vector<std::vector<i8>> distance(8, std::vector<i8>(8, 0));

  q.push(start);
  visited[start.x][start.y] = true;

  while (!q.empty()) {
    auto current = q.front();
    q.pop();

    for (const auto& dir : directions) {
      i8 new_x = current.x + dir.x;
      i8 new_y = current.y + dir.y;

      if (is_valid(new_x, new_y) && !visited[new_x][new_y]) {
        visited[new_x][new_y] = true;
        distance[new_x][new_y] = distance[current.x][current.y] + 1;
        q.push({new_x, new_y});

        if (new_x == target.x && new_y == target.y) {
          return distance[new_x][new_y];
        }
      }
    }
  }

  return -1;
}

i32 solve_for_pawn(pos start, pos end) {
  if (start.x != end.x || start.y < end.y) {
    return -1;
  }

  return end.y - start.y;
}

i32 main() {
  i32 queries;
  std::cin >> queries;

  for (i32 i = 0; i < queries; i++) {
    std::string figure, start_pos, end_pos;
    std::cin >> figure >> start_pos >> end_pos;

    if (figure == "KING") {
      std::cout << solve_for_king(start_pos, end_pos) << '\n';
    } else if (figure == "PAWN") {
      std::cout << solve_for_pawn(start_pos, end_pos) << '\n';
    } else {
      std::cout << "???\n";
      exit(1);
    }
  }

  return 0;
}
