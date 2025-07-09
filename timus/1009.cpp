#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<long long> nums(20, 0);

  nums[0] = 1;
  nums[1] = k - 1;
  for (int i = 2; i <= n; i++) {
    nums[i] = (k - 1) * (nums[i - 1] + nums[i - 2]);
  }

  std::cout << nums[n] << std::endl;
  return 0;
}
