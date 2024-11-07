#include <cstdint>
#include <iostream>

int main() {
  std::ios::sync_with_stdio(0);
  uint64_t n, k, l = 0, r = 1e9;
  std::cin >> n >> k;
  uint64_t array[n];
  for (auto &el : array) {
    std::cin >> el;
  }

  while (l < r) {
    uint64_t m = (l + r) / 2;
    uint64_t an = 0;

    if (m == 0) {
      l = r;
      break;
    }

    for (uint64_t i = 0; i < n; ++i) an += array[i] / m;
    if (an >= k)
      l = m + 1;
    else
      r = m;
  }

  std::cout << l - 1 << std::endl;

  return 0;
}
