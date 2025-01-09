#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

struct int_m_one {
  int number = -1;

  operator int() { return this->number; }
  int_m_one(int n) { this->number = n; }
  int_m_one() {}
};

typedef std::map<std::pair<int, int>, int_m_one> dp_type;

int lcs(dp_type &dp, std::vector<int> &x, std::vector<int> &y, int m, int n) {
  if (m == 0 || n == 0) {
    return 0;
  }

  if (dp[std::make_pair(m, n)] != -1) {
    return dp[std::make_pair(m, n)];
  }

  if (x[m] == y[n]) {
    return dp[std::make_pair(m, n)] = 1 + lcs(dp, x, y, m - 1, n - 1);
  } else {
    return dp[std::make_pair(m, n)] =
               std::max(lcs(dp, x, y, m, n - 1), lcs(dp, x, y, m - 1, n));
  }
}

int main(void) {
  int n, m;

  std::cin >> n;
  std::vector<int> x(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> x[i];
  }

  std::cin >> m;
  std::vector<int> y(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> y[i];
  }

  dp_type dp;
  int res = lcs(dp, x, y, n, m);

  std::cout << res << std::endl;

  return 0;
}
