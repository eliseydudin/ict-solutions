#include <cstdint>
#include <iostream>

int main() {
  std::uint64_t a, b, c;
  std::cin >> a >> b >> c;

  uint64_t sum = a * 2 + b * 3 + c * 4, n = a + b + c, l = -1, r = 4 * n + 1, m;

  while (r - l > 1) {
    m = (r + l) / 2;

    if ((sum + 5 * m) * 2 >= (n + m) * 7)
      r = m;
    else
      l = m;
  }

  std::cout << r << std::endl;

  return 0;
}
