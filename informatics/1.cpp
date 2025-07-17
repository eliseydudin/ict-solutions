#include <iostream>
#include <vector>

int count(std::vector<int>& positions, int distance) {
  int prev_position = positions[0];
  int count = 1;

  for (int i = 1; i < positions.size(); i++) {
    if (positions[i] - prev_position >= distance) {
      count++;
      prev_position = positions[i];
    }
  }

  return count;
}

int bin_search(std::vector<int>& positions, int target) {
  int left = 0, right = (positions.back() - positions[0] + 1);

  while (left + 1 < right) {
    int mid = (left + right) / 2;
    int mid_count = count(positions, mid);

    if (mid_count >= target) {
      left = mid;
    } else {
      right = mid;
    }
  }

  return left;
}

int main() {
  int count, target;
  std::cin >> count >> target;
  std::vector<int> nums(count);

  for (auto& el : nums) {
    std::cin >> el;
  }

  std::cout << bin_search(nums, target) << std::endl;

  return 0;
}
