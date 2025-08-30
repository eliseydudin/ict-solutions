// DOESN'T WORK

#include <cstdint>
#include <iostream>

int main() {
  int64_t a, b, c, d, k;
  std::cin >> a >> b >> c >> d >> k;

  int64_t actual_moves = 0;
  auto coord = std::make_pair(0, 0);
  std::pair<int64_t, int64_t> moves[] = {{0, -a}, {-b, 0}, {0, c}, {d, 0}};
  bool running = true;

  while (running) {
    for (auto move : moves) {
      coord.first += move.first;
      coord.second += move.second;
      actual_moves += std::abs(move.first) + std::abs(move.second);

      if (std::abs(coord.first) >= k || std::abs(coord.second) >= k) {
        actual_moves -=
            std::max(std::abs(coord.first) - k, std::abs(coord.second) - k);
        running = false;
        break;
      }
    }
  }

  std::cout << actual_moves << std::endl;

  return 0;
}
