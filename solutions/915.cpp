#include <iostream>
using i64 = long long;

int main() {
  i64 n;
  std::cin >> n;
  i64 cost[n], ans[n];
  for (auto& el : cost) std::cin >> el;

  ans[0] = cost[0];
  ans[1] = cost[1];

  for (i64 i = 2; i < n; ++i) {
    ans[i] = std::min(ans[i - 1], ans[i - 2]) + cost[i];
  }

  std::cout << ans[n - 1] << std::endl;
}
