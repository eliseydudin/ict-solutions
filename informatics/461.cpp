#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int arr[n][n];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) std::cin >> arr[i][j];

  for (int i = 0; i < n; i++)
    if (arr[i][i]) {
      std::cout << "YES" << std::endl;
      return 0;
    }

  std::cout << "NO" << std::endl;
  return 0;
}
