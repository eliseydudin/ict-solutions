#include <iostream>

int main() {
  // иуиуиуиууиуиуиу
  uint64_t a, b, c, t;
  std::cin >> t >> a >> b >> c;

  if (t == a || t == b || t == c) {
    std::cout << 0 << std::endl;
    return 0;
  }

  a -= t % a;
  b -= t % b;
  c -= t % c;
  std::cout << std::min(std::min(a, b), c) << std::endl;

  return 0;
}
