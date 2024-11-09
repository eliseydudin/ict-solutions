#include <iostream>

int main() {
  int n, k, i, count = 0;
  std::cin >> n >> k;

  int autos[n];

  for (int i = 0; i < n; i++) {
    std::cin >> autos[i];
  }

  int l = 0, r = 0;
  long long sum = autos[0];

  while (r != n) {
    if (sum == k) {
      count++;
      sum -= autos[l++];
    } else if (sum < k) {
      r++;
      sum += autos[r];
    } else if (sum > k) {
      sum -= autos[l++];
    }
  }

  std::cout << count << std::endl;
  return 0;
}
