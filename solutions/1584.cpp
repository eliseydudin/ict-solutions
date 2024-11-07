#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int arr[n];

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  int sum = 0, ans = 0, ind1 = 0, ind2 = 0, minus_pos = -1;

  for (int ind = 0; ind < n; ind++) {
    sum += arr[ind];
    if (sum > ans) {
      ans = sum;
      ind1 = 1 + minus_pos;
      ind2 = ind;
    }
    if (sum <= 0) {
      sum = 0;
      minus_pos = ind;
    }
  }
  std::cout << ++ind1 << "\n" << ++ind2 << "\n";

  return 0;
}
