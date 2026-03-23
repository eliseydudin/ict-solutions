#include <climits>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> matrix(n, std::vector<int>(n));

  for (auto& row : matrix) {
    for (auto& el : row) {
      std::cin >> el;
    }
  }

  int dist, min_dist = INT_MAX;
  int x, y, z;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;

      for (int k = 0; k < n; k++) {
        if (k != j && k != i &&
            (dist = matrix[i][j] + matrix[j][k] + matrix[k][i]) < min_dist) {
          min_dist = dist;
          x = j + 1;
          y = k + 1;
          z = i + 1;
        }
      }
    }
  }

  std::cout << z << ' ' << x << ' ' << y << std::endl;

  return 0;
}
