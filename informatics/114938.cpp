#include <algorithm>
#include <iostream>
#include <vector>

const int inf = 1e9 + 7;

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;
  std::cin >> n;
  std::vector<int> c(n);
  for (int i = 0; i < n; ++i) std::cin >> c[i];
  std::sort(c.begin(), c.end());
  std::vector<int> ans(n + 1);
  std::vector<int> dp(n + 1, -inf);
  dp[0] = 0;

  for (int i = 1; i <= n; ++i) {
    if (c[i - 1] <= i) {
      dp[i] = dp[i - c[i - 1]] + 1;
      ans[dp[i] + n - i] = std::max(ans[dp[i] + n - i], i);
    } else {
      if (c[i - 1] <= n) {
        ans[1 + n - c[i - 1]] = std::max(ans[1 + n - c[i - 1]], i);
      }
    }
    dp[i] = std::max(dp[i], dp[i - 1]);
  }

  for (int i = n - 1; i >= 0; i--) ans[i] = std::max(ans[i], ans[i + 1]);

  int q;
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    int x;
    std::cin >> x;
    std::cout << ans[x] << '\n';
  }

  return 0;
}
