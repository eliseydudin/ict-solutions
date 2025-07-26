#include <cmath>
#include <iostream>
#include <vector>

int find_closest(std::vector<int> &nums, int target) {
  int res = nums[0];
  int left = 0, right = nums.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (abs(nums[mid] - target) < abs(res - target)) {
      res = nums[mid];
    } else if (abs(nums[mid] - target) == abs(res - target)) {
      res = std::min(res, nums[mid]);
    }

    if (nums[mid] == target) {
      return nums[mid];
    } else if (nums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return res;
}

int main() {
  int n, k, input;
  std::cin >> n >> k;
  std::vector<int> nums(n);
  for (auto &el : nums) std::cin >> el;

  for (int i = 0; i < k; i++) {
    std::cin >> input;
    std::cout << find_closest(nums, input) << '\n';
  }

  return 0;
}
