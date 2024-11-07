#include <iostream>

int main() {
  int n, tmp, max = -30001, count = 0;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> tmp;
    if (tmp > max) {
      max = tmp;
      count = 1;
    } else if (tmp == max)
      count++;
  }

  std::cout << count << std::endl;

  return 0;
}
