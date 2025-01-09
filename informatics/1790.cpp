#include <algorithm>
#include <iostream>
#include <vector>

const int N = 1002;
int x[N], y[N], a[N][N];

int main() {
  int n, m;

  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> x[i];
  }

  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    std::cin >> y[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (x[i] == y[j]) {
        a[i][j] = 1 + a[i - 1][j - 1];
      } else {
        a[i][j] = std::max(a[i - 1][j], a[i][j - 1]);
      }
    }
  }

  std::vector<int> v;

  int i = n, j = m;

  while (i && j) {
    if (x[i] == y[j]) {
      v.push_back(x[i]);
      i--;
      j--;
    } else if (a[i - 1][j] == a[i][j]) {
      i--;
    } else {
      j--;
    }
  }

  for (int k = v.size() - 1; k >= 0; k--) {
    std::cout << v[k] << ' ';
  }

  std::cout << std::endl;

  return 0;
}
