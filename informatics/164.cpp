#include <iostream>
#include <vector>

void dfs(int num, std::vector<std::vector<int>> &matrix,
         std::vector<bool> &used) {
  for (int i = 0; i < matrix.size(); i++) {
    if (matrix[num][i] && !used[i]) {
      used[i] = true;
      dfs(i, matrix, used);
    }
  }
}

int dfs_helper(int target, std::vector<std::vector<int>> &matrix) {
  std::vector<bool> used(matrix.size(), false);
  used[target] = true;
  dfs(target, matrix, used);

  int count = 0;
  for (auto el : used) {
    if (el) count++;
  }

  return count;
}

int main() {
  int n, target;
  std::cin >> n >> target;

  std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
  for (auto &el : matrix) {
    for (auto &el2 : el) {
      std::cin >> el2;
    }
  }

  std::cout << dfs_helper(--target, matrix) << std::endl;
  return 0;
}
