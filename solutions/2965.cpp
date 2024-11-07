#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> arr(n, std::vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i > 0 && j > 0) {
        arr[i][j] += std::max(arr[i - 1][j], arr[i][j - 1]);
      } else if (i > 0) {
        arr[i][j] += arr[i - 1][j];
      } else if (j > 0) {
        arr[i][j] += arr[i][j - 1];
      }
    }
  }

  std::cout << arr[n - 1][m - 1] << std::endl;

  return 0;
}
