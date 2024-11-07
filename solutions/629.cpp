#include <cmath>
#include <iostream>

bool perf(int n) {
  if (n == 1) return false;
  int sum = 1;
  int len = sqrt((double)n);

  for (int i = 2; i <= len; i++) {
    if (n % i == 0) {
      sum += i;
      if (n / i != i) sum += n / i;
    }
  }
  return n == sum;
}
int main() {
  int a, b;
  std::cin >> a >> b;
  bool exist = false;

  for (int i = a; i <= b; i++)
    if (perf(i)) {
      printf("%i\n", i);
      exist = true;
    }

  if (!exist) std::cout << "Absent" << std::endl;

  return 0;
}
