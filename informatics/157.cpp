#include <iostream>
#include <vector>

void solve(int pos, int n, int m, int sum, std::vector<int> &nums,
           std::vector<int> &result, std::vector<int> &current) {
  if (pos == m) {
    if (sum == n) {
      if (result.size() == 0 || current.size() < result.size()) {
        result = current;
      }
      return;
    }
    return;
  }

  solve(pos + 1, n, m, sum, nums, result, current);

  current.push_back(nums[pos]);
  solve(pos + 1, n, m, sum + nums[pos], nums, result, current);

  current.push_back(nums[pos]);
  solve(pos + 1, n, m, sum + nums[pos] * 2, nums, result, current);

  current.pop_back();
  current.pop_back();
}

int main() {
  int n, m, sum = 0;
  std::cin >> n >> m;
  std::vector<int> nums(m), result, current;

  for (auto &el : nums) {
    std::cin >> el;
    sum += el * 2;
  }

  if (sum < n) {
    std::cout << "-1" << std::endl;
    return 0;
  }

  solve(0, n, m, 0, nums, result, current);
  if (result.size() == 0) {
    std::cout << "0" << std::endl;
  } else {
    std::cout << result.size() << std::endl;
    for (auto el : result) std::cout << el << ' ';
    std::cout << std::endl;
  }

  return 0;
}
