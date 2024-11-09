#include <cstdint>
#include <iostream>

int main() {
  uint64_t n, w, h;
  std::cin >> w >> h >> n;

  uint64_t l = 0, r = std::max(w, h) * n, m;

  while (r - l > 1) {
    m = (l + r) / 2;
    if ((m / w) * (m / h) >= n)
      r = m;
    else
      l = m;
  }

  std::cout << r << std::endl;

  return 0;
}
