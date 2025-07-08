#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;

  std::cout << (b - 1) / 2 - a / 2 + 1 << std::endl;

  return 0;
}
