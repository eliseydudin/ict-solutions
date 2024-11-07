#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m;
  int arr[n];
  m %= n;
  for (int &el : arr) std::cin >> el;

  if (m != 0) {
    for (int i = n - m; i < n; ++i) std::cout << arr[i] << " ";
    for (int i = 0; i < n - m; ++i) std::cout << arr[i] << " ";
  } else
    for (int elem : arr) std::cout << elem << " ";
  std::cout << "\n";

  return 0;
}
