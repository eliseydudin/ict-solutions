#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int> > matrix(n, std::vector<int>(m));
  matrix[0][0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x;
      std::cin >> x;
      if (x != 0) {
        if (i != 0) matrix[i][j] += matrix[i - 1][j];

        if (j != 0) matrix[i][j] += matrix[i][j - 1];
      }
    }
  }

  int count = matrix[n - 1][m - 1];
  if (count == 0)
    std::cout << "Impossible" << std::endl;
  else
    std::cout << count << std::endl;

  return 0;
}
