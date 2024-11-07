#include <iostream>
#include <vector>

std::vector<int> dp, p;

int func(int a, int b) {
  if (a == 0) {
    return b;
  }
  return func(b % a, a);
}

int main() {
  int n;
  std::cin >> n;

  if (n <= 1) {
    return 0;
  }

  dp.resize(7 * n);
  p.resize(7 * n);
  dp[1] = 0;

  for (int i = 1; i <= n + 1; ++i) {
    if (dp[i + 1] == 0 || dp[i + 1] > dp[i]) {
      dp[i + 1] = dp[i] + 1;
      p[i + 1] = 1;
    }
    if (dp[i * 2] == 0 || dp[i * 2] > dp[i]) {
      dp[i * 2] = dp[i] + 1;
      p[i * 2] = 2;
    }
    if (dp[i * 3] == 0 || dp[i * 3] > dp[i]) {
      dp[i * 3] = dp[i] + 1;
      p[i * 3] = 3;
    }
  }

  std::vector<int> ans;

  while (n > 1) {
    if (p[n] == 1) {
      ans.push_back(1);
      n -= 1;
    } else if (p[n] == 2) {
      ans.push_back(2);
      n /= 2;
    } else {
      ans.push_back(3);
      n /= 3;
    }
  }

  for (int i = ans.size() - 1; i >= 0; --i) {
    if (ans[i] != 0) {
      std::cout << ans[i];
    }
  }

  return 0;
}
