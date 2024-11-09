#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int i = 0; i < n; i++) std::cin >> a[i];

  std::vector<int> b(k);
  for (int i = 0; i < k; i++) std::cin >> b[i];

  for (int i : b) {
    int l = 0;
    int r = n - 1;
    while (r - l > 1) {
      int m = (r + l) / 2;
      if (a[m] < i)
        l = m;
      else
        r = m;
    }
    if (i - a[l] <= a[r] - i)
      std::cout << a[l] << std::endl;
    else
      std::cout << a[r] << std::endl;
  }

  return 0;
}
