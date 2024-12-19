/* спасибо колянчику */

#include <iostream>

int main() {
  int n = 0, k = 0;
  long long in = 0, mx = -20000000000000000, mn = 20000000000000000;

  std::cin >> n >> k;

  for (int i = 0; i < n; i++) {
    std::cin >> in;
    if (in < mn) {
      mn = in;
    }
    if (in > mx) {
      mx = in;
    }
  }

  std::cout << mx - mn << std::endl;
  return 0;
}
