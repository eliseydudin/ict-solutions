#include <cstdint>
#include <iostream>
#include <vector>

uint64_t solve(std::vector<uint64_t> &nums) {
  uint64_t result = 0;
  uint64_t sum_a = 0, sum_b = 0;

  for (uint64_t i = 0; i < nums.size(); i++) {
    sum_a += (nums[i] * nums[i]);
    sum_b += nums[i];
  }

  sum_a = nums.size() * sum_a;
  sum_b = (sum_b * sum_b);
  result = sum_a - sum_b;

  return result;
}

int main() {
  uint64_t n;
  std::cin >> n;
  std::vector<uint64_t> nums(n);
  for (auto &el : nums) std::cin >> el;

  std::cout << solve(nums) << std::endl;

  return 0;
}
