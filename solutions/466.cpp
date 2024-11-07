#include <iostream>

int main() {
  int n, inp;
  std::cin >> n;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      std::cin >> inp;
      if (inp) std::cout << i + 1 << ' ' << j + 1 << '\n';
    }

  return 0;
}
