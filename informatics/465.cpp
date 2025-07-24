#include <cstring>
#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m;
  int matrix[n][n];
  bzero(matrix, sizeof(matrix));

  for (int i = 0; i < m; i++) {
    int i1, i2;
    std::cin >> i1 >> i2;

    matrix[i1 - 1][i2 - 1] = 1;
    matrix[i2 - 1][i1 - 1] = 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
