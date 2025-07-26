#include <iostream>

int main() {
  int n, count = 0, input;
  std::cin >> n;

  for (int i = 0; i < n * n; i++) {
    std::cin >> input;

    if (input) count++;
  }

  std::cout << count / 2 << std::endl;
  return 0;
}
