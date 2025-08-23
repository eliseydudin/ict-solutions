#include <iostream>

int main() {
  int n, a, b;
  std::cin >> n >> a >> b;

  int b1 = n / 3, a1 = n % 3;
  int n1;

  if (b1 == 0) {
    n1 = a / a1;
  } else if (a1 == 0) {
    n1 = b / b1;
  } else {
    n1 = std::min(a / a1, b / b1);
  }

  int a_end = a - n1 * a1, b_end = b - b1 * n1;

  if (b_end < b1) {
    if (n - 3 * b_end <= a_end) {
      n1++;
    }

    int a_fin = a_end - (n - 3 * b_end);
    n1 += a_fin / n;
  }

  std::cout << n1 << std::endl;

  return 0;
}
