#include <iostream>
#include <vector>

bool dfs(int vertex, std::vector<std::vector<int>> &matrix,
         std::vector<int> &used, int group) {
  for (auto el : matrix[vertex]) {
    if (used[el] == group) {
      return false;
    } else if (used[el] == -1) {
      used[el] = 1 - group;
      if (!dfs(el, matrix, used, 1 - group)) return false;
    }
  }

  return true;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> matrix(n);

  for (int i = 0; i < m; i++) {
    int l, r;
    std::cin >> l >> r;
    matrix[--l].push_back(--r);
    matrix[r].push_back(l);
  }

  std::vector<int> used(n, -1);

  for (int i = 0; i < n; i++) {
    if (used[i] != -1) continue;
    used[i] = 0;
    if (!dfs(i, matrix, used, 0)) {
      std::cout << "NO" << std::endl;
      return 0;
    }
  }

  std::cout << "YES" << std::endl;
  for (int i = 0; i < used.size(); i++) {
    if (used[i] != 0) continue;
    std::cout << i + 1 << ' ';
  }
  std::cout << std::endl;

  return 0;
}
