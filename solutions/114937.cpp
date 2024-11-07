#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  long long n;
  std::cin >> n;
  std::vector<long long> pos_a(n + 1);
  std::vector<long long> pos_b(n + 1);

  for (long long i = 0; i < n; i++) {
    long long a;
    std::cin >> a;
    pos_a[a] = i + 1;
  }
  for (long long i = 0; i < n; i++) {
    long long b;
    std::cin >> b;
    pos_b[b] = i + 1;
  }
  long long la = n, ra = 1, lb = n, rb = 1, ans = 0;

  for (long long i = 1; i + 1 <= n; i++) {
    la = std::min(la, pos_a[i]);
    ra = std::max(ra, pos_a[i]);
    lb = std::min(lb, pos_b[i]);
    rb = std::max(rb, pos_b[i]);

    long long min_la, max_ra, min_lb, max_rb;

    if (pos_a[i + 1] < la) {
      min_la = pos_a[i + 1] + 1;
      max_ra = n;
    } else {
      min_la = 1;
      max_ra = pos_a[i + 1] - 1;
    }
    if (pos_b[i + 1] < lb) {
      min_lb = pos_b[i + 1] + 1;
      max_rb = n;
    } else {
      min_lb = 1;
      max_rb = pos_b[i + 1] - 1;
    }
    ans += std::max(std::min(la, lb) - std::max(min_la, min_lb) + 1, 0ll) *
           std::max(std::min(max_ra, max_rb) - std::max(ra, rb) + 1, 0ll);
  }
  ans += std::min(pos_a[1], pos_b[1]) * (std::min(pos_a[1], pos_b[1]) - 1) / 2;
  ans += (n - std::max(pos_a[1], pos_b[1])) *
         (n - std::max(pos_a[1], pos_b[1]) + 1) / 2;
  ans += abs(pos_a[1] - pos_b[1]) * (abs(pos_a[1] - pos_b[1]) - 1) / 2;
  ans++;

  std::cout << ans << std::endl;
}

int main() {
  solve();
  return 0;
}
