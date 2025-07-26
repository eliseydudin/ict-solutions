#include <cmath>
#include <iostream>

int main() {
  int n;
  std::cin >> n;

  double log = std::log2(n);
  std::cout << (int)std::ceil(log) << std::endl;

  return 0;
}
