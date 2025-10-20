// #include <cmath>
#include <iostream>

int main() {
  int k, n;
  std::cin >> k >> n;
  int page = n / k + 1;
  int line = n % k;

  if (line == 0) {
    std::cout << --page << ' ' << k << std::endl;
  } else {
    std::cout << page << ' ' << line << std::endl;
  }

  return 0;
}
