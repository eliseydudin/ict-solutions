#include <climits>
#include <iostream>
#include <vector>

int main() {
  int n, min = INT_MAX, max = INT_MIN;
  std::cin >> n;
  std::vector<int> nums(n, 0);

  for (auto &el : nums) {
    std::cin >> el;

    if (el < min) min = el;
    if (el > max) max = el;
  }

  for (auto &el : nums) {
    if (el == max)
      std::cout << min << ' ';
    else
      std::cout << el << ' ';
  }

  std::cout << std::endl;

  return 0;
}
