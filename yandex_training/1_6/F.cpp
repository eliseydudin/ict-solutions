#include <cstdint>
#include <iostream>

int main() {
  uint64_t n, x, y;
  std::cin >> n >> x >> y;
  n--;

  uint64_t l = -1, r = n * std::max(x, y), m, printed;
  while (r - l > 1) {
    m = (l + r) / 2;
    printed = m / x + m / y;

    if (printed >= n)
      r = m;
    else
      l = m;
  }

  std::cout << r + std::min(x, y) << std::endl;

  return 0;
}
