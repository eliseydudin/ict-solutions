#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);

  for (int &i : a) std::cin >> i;

  int l = 0, r = n - 1;
  int mn = 1, mx = n;

  while (l <= r) {
    if (a[l] == mn) {
      l++;
      mn++;
    } else if (a[l] == mx) {
      l++;
      mx--;
    } else if (a[r] == mn) {
      r--;
      mn++;
    } else if (a[r] == mx) {
      r--;
      mx--;
    } else {
      break;
    }
  }
  if (l <= r)
    std::cout << l + 1 << " " << r + 1 << std::endl;
  else
    std::cout << -1 << std::endl;
}

int main() {
  solve();
  return 0;
}
