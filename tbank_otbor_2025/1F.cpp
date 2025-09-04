// FIX
// fails on test 6

#include <iostream>
#include <vector>

int main() {
  int n, m, inp;
  std::cin >> n >> m;
  std::vector<std::vector<int>> mat(n, std::vector<int>(m));
  std::vector<int> rows(n), column_ones_count(m);

  for (int i = 0; i < n; i++) {
    std::cin >> rows[i];

    if (!rows[i])
      continue;  // technically all rows have an even number of ones by default

    column_ones_count[0]++;
    mat[i][0] = 1;  // make the number odd
  }

  for (int j = 0; j < m; j++) {
    std::cin >> inp;
    if (column_ones_count[j] % 2 == inp) {
      // everything is okay, ignore
      continue;
    }

    if (j == m - 1) {
      std::cout << "NO" << std::endl;
      return 0;
    } else if (j < m - 2) {
    }

    column_ones_count[j]--;
    column_ones_count[j + 1]++;
    for (int i = 0; i < m; i++) {
      if (!mat[i][j]) continue;
      std::swap(mat[i][j], mat[i][j + 1]);
      break;
    }
  }

  std::cout << "YES\n";
  for (auto &arr : mat) {
    for (auto &el : arr) {
      std::cout << el << ' ';
    }

    std::cout << '\n';
  }

  return 0;
}
