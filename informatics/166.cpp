#include <iostream>
#include <vector>

bool dfs(int i, std::vector<bool> &visited, std::vector<bool> &traversed,
         std::vector<std::vector<int>> &mat, std::vector<int> &result) {
  if (traversed[i]) {
    return false;
  }

  traversed[i] = true;

  for (auto j : mat[i]) {
    if (!visited[j] && !dfs(j, visited, traversed, mat, result)) {
      return false;
    }
  }

  traversed[i] = false;
  visited[i] = true;
  result.push_back(i);

  return true;
}

bool solve_helper(std::vector<std::vector<int>> &mat, int n,
                  std::vector<int> &result) {
  std::vector<bool> visited(n, false), traversed(n, false);

  for (int i = 0; i < n; i++) {
    if (!visited[i] && !dfs(i, visited, traversed, mat, result)) {
      return false;
    }
  }

  return true;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> matrix(n);

  for (int i = 0; i < m; i++) {
    int k, j;
    std::cin >> k >> j;

    matrix[--j].push_back(--k);
  }

  std::vector<int> result;

  if (solve_helper(matrix, n, result)) {
    std::cout << "Yes" << std::endl;
    for (auto el : result) {
      std::cout << ++el << ' ';
    }
    std::cout << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
