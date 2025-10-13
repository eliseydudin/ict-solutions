/* DOESNT WORK */

#include <iostream>
#include <numeric>
#include <vector>

bool check(int k, int mid, std::vector<int> &nums) {
  int tomes = 0, curr = 0;

  for (auto a : nums) {
    if (mid <= a) {
      return false;
    } else if (curr + a == mid) {
      curr = 0;
      mid++;
    } else if (curr + a < mid) {
      curr += a;
    } else {
      tomes++;
      curr = mid;
    }
  }

  if (tomes < k) {
    return false;
  }

  return true;
}

int bin_search(int left, int right, int k, std::vector<int> &nums) {
  while (right - left > 1) {
    int mid = (left + right) / 2;

    if (check(k, mid, nums)) {
      right = mid;
    } else {
      left = mid;
    }
  }

  return left;
}

int main() {
  int n, k;
  std::cin >> n;
  std::vector<int> nums(n);
  for (auto &el : nums) std::cin >> el;
  std::cin >> k;

  int left = 1, right = std::accumulate(nums.begin(), nums.end(), 0);
  std::cout << bin_search(left, right, k, nums) << std::endl;

  return 0;
}
