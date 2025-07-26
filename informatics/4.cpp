#include <iostream>
#include <vector>

int bin_search(std::vector<int> &arr, int target) {
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

int main() {
  int n, k, input;
  std::cin >> n >> k;
  std::vector<int> nums(n);
  for (auto &el : nums) std::cin >> el;

  for (int i = 0; i < k; i++) {
    std::cin >> input;
    int pos = bin_search(nums, input);
    if (pos == -1) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
    }
  }

  return 0;
}
