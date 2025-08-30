// DOESN'T WORK
// should check 4 points

#include <cstdint>
#include <iostream>

int64_t solve(int64_t a, int64_t b, int64_t c, int64_t d, int64_t k) {
  std::pair<int, int> orig{0, 0};

  int64_t moves_per_turn = a + b + c + d;
  int64_t move_x = std::abs(d - b), move_y = std::abs(c - a);
  int64_t min_op = std::min(k / move_x, k / move_y);
  int64_t actual_moves = moves_per_turn * min_op;

  if (min_op * std::max(move_x, move_y) < k) {
    auto coord = std::make_pair(min_op * move_x, min_op * move_y);
    std::pair<int64_t, int64_t> moves[] = {{0, -a}, {-b, 0}, {0, c}, {d, 0}};

    for (auto move : moves) {
      coord.first += move.first;
      coord.second += move.second;
      actual_moves += std::abs(move.first) + std::abs(move.second);

      if (std::abs(coord.first) >= k || std::abs(coord.second) >= k) {
        actual_moves -=
            std::max(std::abs(coord.first) - k, std::abs(coord.second) - k);
        break;
      }
    }
  }

  return actual_moves;
}

int main() {
  int64_t a, b, c, d, k;
  std::cin >> a >> b >> c >> d >> k;
  std::cout << solve(a, b, c, d, k) << std::endl;

  return 0;
}
