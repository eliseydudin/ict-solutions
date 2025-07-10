#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m;

  int matrix[n][m];
  int row_mins[n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> matrix[i][j];

      if (j == 0) {
        row_mins[i] = matrix[i][j];
      } else {
        row_mins[i] = std::min(row_mins[i], matrix[i][j]);
      }
    }
  }

  int column_maxes[m];

  for (int j = 0; j < m; j++) {
    column_maxes[j] = matrix[0][j];

    for (int i = 0; i < n; i++) {
      column_maxes[j] = std::max(matrix[i][j], column_maxes[j]);
    }
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int num = matrix[i][j];

      if (num == row_mins[i] && num == column_maxes[j]) {
        count++;
      }
    }
  }

  std::cout << count << std::endl;

  return 0;
}
