#include <iostream>
#include <vector>

std::vector<std::vector<int>> generate_square(int n) {
  std::vector<std::vector<int>> mat(n, std::vector<int>(n, 0));
  int i = n / 2;
  int j = n - 1;

  for (int num = 1; num <= n * n;) {
    if (i == -1 && j == n) {
      j = n - 2;
      i = 0;
    } else {
      if (j == n) j = 0;

      if (i < 0) i = n - 1;
    }

    if (mat[i][j]) {
      j -= 2;
      i++;
      continue;
    } else {
      mat[i][j] = num++;
    }

    j++;
    i--;
  }

  return mat;
}

int main() {
  int n;
  std::cin >> n;
  auto result = generate_square(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << result[i][j] << ' ';
    }

    std::cout << '\n';
  }
  std::cout << std::endl;

  return 0;
}
