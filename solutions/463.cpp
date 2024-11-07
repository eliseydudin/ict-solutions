#include <iostream>

int main() {
  int n, c;
  size_t count = 0;
  std::cin >> n;

  for (int i = 0; i < (n * n); i++) {
    std::cin >> c;
    if (c) count++;
  }

  std::cout << count << std::endl;

  return 0;
}
