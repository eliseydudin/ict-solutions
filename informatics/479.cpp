#include <cstring>
#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m;

  int arr[n][n];
  bzero(arr, sizeof(arr));

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

  if (result) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  std::cout << std::endl;

  return 0;
}
