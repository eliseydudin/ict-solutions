#include <cstdint>
#include <iostream>

int main() {
  uint64_t n;
  std::cin >> n;

  if (n == 1 || n == 2) {
    std::cout << 2 << std::endl;
    return 0;
  }

  uint64_t p1 = 2, p2 = 2;
  for (uint64_t i = 0; i < n - 2; i++) {
    uint64_t new_p = p2 + p1;
    p1 = p2;
    p2 = new_p;
  }

  std::cout << p2 << std::endl;

  return 0;
}
