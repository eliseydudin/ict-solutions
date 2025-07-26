#include <iostream>
#include <stack>
#include <vector>

int dfs(int n, int target, std::vector<std::vector<int>> &matrix) {
  std::vector<bool> used(n, false);
  std::stack<int> visited;
  visited.push(target);
  used[target] = 1;

  while (!visited.empty()) {
    int num = visited.top();
    visited.pop();

    for (int i = 0; i < n; i++) {
      if (used[i]) continue;
      auto &el = matrix[num][i];

      if (el) {
        visited.push(el);
        used[i] = true;
      }
    }
  }

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

  std::cout << dfs(n, --target, matrix) << std::endl;
  return 0;
}
