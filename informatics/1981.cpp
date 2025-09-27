#include <iostream>

int main() {
  int a, b, c, x, k;
  std::cin >> a >> b >> c >> x >> k;

  int div = x / k;
  if (div < a || div > b) {
    std::cout << div << std::endl;
  } else {
    float new_c = (c / 100.0f + 1.0f) * k;
    std::cout << std::max(a - 1, (int)((float)x / new_c)) << std::endl;
  }

  return 0;
}
