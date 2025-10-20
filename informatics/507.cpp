#include <iostream>
#include <vector>

bool is_sym(std::vector<int>::iterator first, std::vector<int>::iterator last) {
  if (first >= last) return true;
  if (*first != *last) return false;
  return is_sym(first + 1, last - 1);
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> nums(n, 0);
  for (auto& el : nums) std::cin >> el;

  int counter = 0;
  auto start = nums.begin();

  while (!is_sym(start, nums.end() - 1)) {
    ++counter;
    ++start;
  }

  std::cout << counter << std::endl;
  for (int i = counter - 1; i >= 0; --i) std::cout << nums[i] << ' ';
  std::cout << std::endl;

  return 0;
}
