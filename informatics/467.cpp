#include <cstring>
#include <iostream>

int main() {
  unsigned n, m, a, b;
  std::cin >> n >> m;
  bool arr[n][n];
  std::memset(arr, false, n * n);

  for (int i = 0; i < m; i++) {
    std::cin >> a >> b;
    arr[a - 1][b - 1] = true;
  }

  for (unsigned i = 0; i < n; i++) {
    for (unsigned j = 0; j < n; j++) std::cout << arr[i][j] << " ";
    std::cout << '\n';
  }

  return 0;
}
