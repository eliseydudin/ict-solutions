// 41/42

#include <iostream>
#include <set>
#include <vector>

using matrix_t = std::vector<std::set<int>>;

bool dfs(int target, int parent, matrix_t &mat, std::vector<bool> &used) {
  for (int neighbour : mat[target]) {
    if (neighbour == parent) {
      continue;
    } else if (used[neighbour]) {
      return false;
    }

    used[neighbour] = true;
    if (!dfs(neighbour, target, mat, used)) {
      return false;
    }
  }

  return true;
}

bool is_tree(matrix_t &mat, std::vector<bool> &used) {
  for (int i = 0; i < mat.size(); i++) {
    if (used[i]) {
      continue;
    } else if (mat[i].size() == 0) {
      return false;
    }

    used[i] = true;
    auto res = dfs(i, -1, mat, used);
    if (!res) return false;
  }

  return true;
}

int main() {
  int n, input;
  std::cin >> n;
  matrix_t matrix(n);
  std::vector<bool> used(n, false);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> input;
      if (!input) continue;
      matrix[i].insert(j);
      matrix[j].insert(i);
    }
  }

  if (is_tree(matrix, used)) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  std::cout << std::endl;

  return 0;
}
