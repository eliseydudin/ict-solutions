#include <cstring>
#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> arr(n, std::vector<int>(n, 0));

  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;

    arr[a - 1][b - 1] = 1;
    arr[b - 1][a - 1] = 1;
  }

  int result = 1;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (k == i || k == j) continue;
        if (arr[i][k] && arr[k][j]) result &= arr[i][j];
      }
    }
  }

  std::cout << (result ? "YES" : "NO") << std::endl;

  return 0;
}
