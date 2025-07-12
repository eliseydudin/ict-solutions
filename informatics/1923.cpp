#include <cstdint>
#include <iostream>

using u64 = uint64_t;

u64 get_max(u64 width, u64 w, u64 h) {
  u64 k = (width / h) * (width / w);
  return k;
}

u64 left_bin_search(u64 n, u64 w, u64 h) {
  u64 left = 1, right = std::max(w, h) * n;

  while (right - left > 1) {
    u64 mid = (left + right) / 2;

    if (get_max(mid, w, h) < n) {
      left = mid;
    } else {
      right = mid;
    }
  }

  return right;
}

int main() {
  u64 w, h, n;
  std::cin >> w >> h >> n;

  std::cout << left_bin_search(n, w, h) << std::endl;
  return 0;
}
