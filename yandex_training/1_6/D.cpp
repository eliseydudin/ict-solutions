#include <iostream>

size_t n, a, b, w, h;

bool check(size_t d) {
  auto hor_n = (w / (a + 2 * d)) * (h / (b + 2 * d));
  auto vert_n = (w / (b + 2 * d)) * (h / (a + 2 * d));

  return (hor_n >= n || vert_n >= n);
}

size_t bin_search(size_t left, size_t right) {
  while (left < right) {
    size_t mid = (left + right + 1) / 2;

    if (check(mid))
      left = mid;
    else
      right = mid - 1;
  }

  return left;
}

int main() {
  std::cin >> n >> a >> b >> w >> h;
  std::cout << bin_search(0, 10000000000000000000ULL) << std::endl;

  return 0;
}
