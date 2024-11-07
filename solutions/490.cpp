#include <cstdint>
#include <iostream>

int main() {
  uint64_t n, x, y;
  std::cin >> n >> x >> y;
  n--;
  uint64_t l = 0, r = n * std::max(x, y), m;
  while (l < r) {
    m = (r + l) / 2;
    if ((m / x + m / y) < n)
      l = m + 1;
    else
      r = m;
  }
  std::cout << r + std::min(x, y) << std::endl;
  return 0;
}
