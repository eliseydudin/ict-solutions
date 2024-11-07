#include <iostream>

typedef long double ld;

ld f(ld x, ld z, ld v, ld u, int n) {
  ld ans = 0;
  ld t1 = x / v;
  x -= t1 * u;
  ans += t1;
  for (int i = 0; i < n; ++i) {
    ans += x / (v + u);
    ans += x / (v - u);
  }
  return ans;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cout.precision(10);
  int n;
  ld z, v, u;
  std::cin >> n >> v >> u >> z;
  if (u >= v) {
    std::cout << z / u;
    return 0;
  }
  if (n <= 4) {
    std::cout << z / v;
    return 0;
  }
  n = (n + 3) / 4;
  --n;
  ld x = (z * v * u * (v + u)) /
         (u * (n * u * (v - u) + n * u * (v + u) + v * (v + u)));
  std::cout << f(x, z, v, u, n) << std::endl;

  return 0;
}
