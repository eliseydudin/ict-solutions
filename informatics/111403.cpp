#include <cmath>
#include <iomanip>
#include <iostream>

inline double solve_helper(double number) {
  return number * number + std::sqrt(number);
}

int main() {
  double c;
  std::cin >> c;

  double l = 0.0, r = std::sqrt(c);
  while (r - l > 1e-10) {
    double mid = (l + r) / 2.0;

    if (solve_helper(mid) < c) {
      l = mid;
    } else {
      r = mid;
    }
  }

  std::cout << std::fixed << std::setprecision(9) << r << std::endl;
  return 0;
}
