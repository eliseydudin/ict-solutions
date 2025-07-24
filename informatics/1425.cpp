#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> nums(107, 0), input(n, 0);
  for (auto &el : input) std::cin >> el;

  int min = *std::min_element(input.begin(), input.end());

  for (auto &el : input) {
    nums[el - min]++;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 0) {
      continue;
    }

    for (int j = 0; j < nums[i]; j++) {
      std::cout << i + min << ' ';
    }
  }
  std::cout << std::endl;

  return 0;
}
