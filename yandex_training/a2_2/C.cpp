/* спасибо легенде колянчику */

#include <iostream>
#include <vector>

int main() {
  int n, p = 0, x, y;
  std::cin >> n;
  std::vector<std::vector<int>> arr(10, std::vector<int>(10, 0));

  for (int i = 0; i < n; ++i) {
    std::cin >> x >> y;
    arr[y][x] = 1;
  }

  for (int i = 1; i < 9; ++i) {
    for (int j = 1; j < 9; ++j) {
      if (arr[i][j] == 1) {
        if (arr[i - 1][j] == 0) {
          p += 1;
        }
        if (arr[i][j - 1] == 0) {
          p += 1;
        }
        if (arr[i + 1][j] == 0) {
          p += 1;
        }
        if (arr[i][j + 1] == 0) {
          p += 1;
        }
      }
    }
  }

  std::cout << p << std::endl;
  return 0;
}
