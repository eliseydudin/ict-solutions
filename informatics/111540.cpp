// 75/100

#include <iostream>
#include <set>
#include <vector>

void dfs(size_t num, std::vector<std::vector<size_t>> &matrix,
         std::vector<bool> &used) {
  for (size_t i = 0; i < matrix.size(); i++) {
    if (matrix[num][i] && !used[i]) {
      used[i] = true;
      dfs(i, matrix, used);
    }
  }
}

std::vector<bool> dfs_helper(size_t target,
                             std::vector<std::vector<size_t>> &matrix) {
  std::vector<bool> used(matrix.size(), false);
  used[target] = true;
  dfs(target, matrix, used);

  return used;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  std::vector<std::vector<size_t>> matrix(n, std::vector<size_t>(n));
  std::vector<std::vector<size_t>> results;

  std::set<size_t> to_search_for;
  for (size_t i = 0; i < n; i++) {
    to_search_for.insert(i);
  }

  for (size_t i = 0; i < m; i++) {
    size_t l, r;
    std::cin >> l >> r;
    matrix[--l][--r] = 1;
    matrix[r][l] = 1;
  }

  while (!to_search_for.empty()) {
    size_t search = *to_search_for.begin();
    std::vector<bool> adj = dfs_helper(search, matrix);

    std::vector<size_t> res;
    for (size_t i = 0; i < adj.size(); i++) {
      if (!adj[i]) continue;
      res.push_back(i);
      to_search_for.erase(i);
    }

    results.push_back(res);
  }

  std::cout << results.size() << std::endl;
  for (auto &res : results) {
    std::cout << res.size() << "\n";
    for (auto elem : res) {
      std::cout << ++elem << " ";
    }
    std::cout << "\n";
  }

  return 0;
}
