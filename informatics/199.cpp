#include <iostream>

int gcd(int a, int b) {
  if (a == 0 || b == 0) {
    return std::max(a, b);
  }

  return gcd(std::max(a, b) % std::min(a, b), std::min(a, b));
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;

  return 0;
}
