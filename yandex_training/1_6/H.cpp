#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

uint64_t n, k;
std::vector<uint64_t> arr;

bool check(uint64_t mid) {
  auto count = 0ULL;
  for (auto&& t : arr) count += t / mid;

  return count >= k;
}

uint64_t bin_search() {
  uint64_t l = 0ULL, r = *std::max_element(arr.begin(), arr.end()) + 1;

  while (r - l > 1) {
    auto mid = (l + r) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }

  return l;
}

int main() {
  std::cin >> n >> k;

  arr = std::vector<uint64_t>(n, 0);
  for (auto& t : arr) std::cin >> t;

  std::sort(arr.begin(), arr.end());

  std::cout << bin_search() << std::endl;

  return 0;
}
