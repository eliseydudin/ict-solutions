#include <iostream>
#include <vector>

void dfs(int vertex, std::vector<std::vector<int>> &matrix,
         std::vector<int> &used, int group) {
  for (auto el : matrix[vertex]) {
    if (used[el] != -1) continue;
    used[el] = group;
    dfs(el, matrix, used, group);
  }
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

  int group = 0;
  std::vector<int> used(n, -1);
  for (int i = 0; i < n; i++) {
    if (used[i] != -1) continue;

    used[i] = group;
    dfs(i, matrix, used, group++);
  }

  std::vector<std::vector<int>> results(group);

  std::cout << group << std::endl;
  for (int i = 0; i < n; i++) {
    results[used[i]].push_back(i);
  }

  for (auto &res : results) {
    std::cout << res.size() << '\n';
    for (auto el : res) {
      std::cout << ++el << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
