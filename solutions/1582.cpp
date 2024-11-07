#include <iostream>

int main() {
  int n, zeros = 0, input;
  std::cin >> n;
  int arr[n];

  int index = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> input;
    if (input != 0)
      arr[index++] = input;
    else
      zeros++;
  }

  for (int i = 0; i < n - zeros; i++) std::cout << arr[i] << " ";
  for (int i = 0; i < zeros; i++) std::cout << 0 << " ";

  std::cout << "\n";

  return 0;
}
