#include <iostream>
#include <vector>

int left_bin_search(std::vector<int> &arr, int target) {
  int left = -1, right = arr.size();

  while (right - left > 1) {
    int mid = (left + right) / 2;

    if (arr[mid] < target) {
      left = mid;
    } else {
      right = mid;
    }
  }

  if (right == arr.size() || arr[right] != target) {
    return -1;
  }

  return right;
}

int right_bin_search(std::vector<int> &arr, int target) {
  int left = -1, right = arr.size();

  while (right - left > 1) {
    int mid = (left + right) / 2;

    if (arr[mid] <= target) {
      left = mid;
    } else {
      right = mid;
    }
  }

  if (left == -1 || arr[left] != target) {
    return -1;
  }

  return left;
}

int main() {
  int n, k, input;
  std::cin >> n >> k;

  std::vector<int> nums(n, 0);

  for (auto &el : nums) std::cin >> el;

  for (int i = 0; i < k; i++) {
    std::cin >> input;

    int result1 = left_bin_search(nums, input),
        result2 = right_bin_search(nums, input);

    if (result1 == -1) {
      std::cout << "0\n";
    } else {
      std::cout << ++result1 << ' ' << ++result2 << '\n';
    }
  }
}
