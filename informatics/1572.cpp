#include <algorithm>
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int arr[n];

  for (int &el : arr) std::cin >> el;

  for (auto elem : arr) {
    if (std::count(&arr[0], &arr[n + 1], elem) == 1) std::cout << elem << ' ';
  }
  std::cout << '\n';

  return 0;
}
