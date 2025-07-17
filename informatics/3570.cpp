#include <cmath>
#include <iomanip>
#include <iostream>

double solve(double range_start, double range_end, double precision, int n,
             double target) {
  while (std::abs(range_end - range_start) >= precision) {
    double mid = (range_start + range_end) / 2;

    if (pow(mid, n) > target) {
      range_end = mid;
    } else {
      range_start = mid;
    }
  }

  return range_end;
}

int main() {
  double number;
  int power;

  std::cin >> number >> power;

  double upper = number < 1.0 ? 1.0 : number;
  std::cout << std::fixed << std::setprecision(7)
            << solve(0.0, upper, 1e-7, power, number) << std::endl;

  return 0;
}
