#include <iostream>

int main() {
  int n, k, m;
  std::cin >> n >> k >> m;
  int arr[n];

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  int sum = 0;
  for (int i = 0; i <= k; i++) sum += arr[i];

  for (int index = 0; index < n - k; index++) {
    if (sum == m) {
      std::cout << index + 1 << "\n";
      return 0;
    }
    sum -= arr[index];
    sum += arr[index + 1 + k];
  }

  std::cout << 0 << "\n";
  return 0;
}
