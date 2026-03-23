#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

  for (int i = 0; i < m; i++) {
    int i1, i2;
    std::cin >> i1 >> i2;

    matrix[i1 - 1][i2 - 1] = 1;
    matrix[i2 - 1][i1 - 1] = 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && !matrix[i][j]) {
        std::cout << "NO" << std::endl;
        return 0;
      }
    }
  }

  std::cout << "YES" << std::endl;

  return 0;
}
