#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;

  if (a >= b) {
    std::cout << 2 * (a - b) + 2 << std::endl;
  } else {
    std::cout << 1 << std::endl;
  }

  return 0;
}
