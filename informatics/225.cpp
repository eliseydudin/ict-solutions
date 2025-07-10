#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int arr[n];
  for (auto &el : arr) std::cin >> el;

  int to_find, current_max = arr[0];
  std::cin >> to_find;

  for (auto &el : arr) {
    if (abs(to_find - el) < abs(to_find - current_max)) current_max = el;
  }

  std::cout << current_max << std::endl;

  return 0;
}
