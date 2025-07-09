#include <iostream>

int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;

  for (int i = 0;;) {
    if (a + (i * b) >= c - (d * i)) {
      std::cout << (a + (i * b)) << std::endl;
      break;
    }

    if (a + ((i + 1) * b) >= c - (d * i)) {
      std::cout << (c - (d * i)) << std::endl;
      break;
    }
  }

  return 0;
}
