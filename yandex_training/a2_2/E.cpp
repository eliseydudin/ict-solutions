/* no worky :( */

#include <cstdint>
#include <iostream>

int64_t kol(int x, int z1, int z2, int x1, int y1, int x2, int y2) {
  int min, max;
  int64_t k;

  if (x < x1 || x > x2 || z1 > y2 || z2 < y1) {
    k = 0;
  } else {
    min = y1;
    if (z1 > y1) {
      min = z1;
    }
    max = y2;
    if (z2 < y2) {
      max = z2;
    }
    k = max - min + 1;
  }
  return k;
}

int main() {
  int x1, y1, x2, y2, x3, y3, x;
  int64_t k, r, y;

  std::cin >> x1 >> y1 >> x2 >> y2;
  std::cin >> x3 >> y3 >> r;

  k = kol(x3, y3 - r, y3 + r, x1, y1, x2, y2);
  y = r;

  for (x = 1; x < r; ++x) {
    while (x * x + y * y > r * r) {
      y--;
    }
    k += kol(x3 + x, y3 - y, y3 + y, x1, y1, x2, y2);
    k += kol(x3 - x, y3 - y, y3 + y, x1, y1, x2, y2);
  }

  k += kol(x3 + r, y3, y3, x1, y1, x2, y2);
  k += kol(x3 - r, y3, y3, x1, y1, x2, y2);

  std::cout << k << std::endl;

  return 0;
}
