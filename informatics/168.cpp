#include <iostream>
#include <set>

const int MAX = 1000000000;

int main() {
  int n, m, i, f, j, k, s, t;

  std::set<std::pair<int, int>> c;
  std::cin >> n >> s >> f;

  s--;
  f--;

  int a[n][n], d[n];
  bool b[n];

  for (i = 0; i < n; ++i) {
    d[i] = MAX;
    b[i] = true;
    for (j = 0; j < n; ++j) {
      std::cin >> a[i][j];
      if (a[i][j] < 0) a[i][j] = MAX;
    }
  }

  d[s] = 0;
  c.insert({0, s});

  while (!c.empty()) {
    i = c.begin()->second;
    b[i] = false;

    c.erase(c.begin());

    for (j = 0; j < n; ++j) {
      if (b[j] && d[j] > d[i] + a[i][j]) {
        c.erase({d[j], j});
        d[j] = d[i] + a[i][j];
        c.insert({d[j], j});
      }
    }
  }

  if (d[f] < MAX) {
    std::cout << d[f] << std::endl;
  } else {
    std::cout << -1 << std::endl;
  }

  return 0;
}
