#include <iostream>

int main() {
  int64_t a, b, n, m;
  std::cin >> a >> b >> n >> m;

  int64_t only_a = n / (m + 1) * m * a + n % (m + 1) * a;
  int64_t only_b = n * b;
  int64_t all = n / (m + 1) * m * a + n % (m + 1) * b;

  std::cout << std::min(only_a, std::min(only_b, all)) << std::endl;

  return 0;
}
