#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> nums(n);
  for (auto &el : nums) std::cin >> el;
  int max = *std::max_element(nums.begin(), nums.end()),
      min = *std::min_element(nums.begin(), nums.end());

  std::vector<int> cache(max - min + 1, 0);

  for (auto &el : nums) {
    cache[el - min]++;
  }

  for (int i = 0; i < cache.size(); i++) {
    if (cache[i] == 0) {
      continue;
    } else {
      for (int j = 0; j < cache[i]; j++) std::cout << (i + min) << ' ';
    }
  }
  std::cout << std::endl;

  return 0;
}
