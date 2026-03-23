#include <iostream>

int main() {
  int n, ret = 0, inp;
  std::cin >> n;

  for (int i = 0; i <= n * n; i++) {
    std::cin >> inp;
    ret += inp;
  }

  std::cout << ret / 2 << std::endl;

  return 0;
}
