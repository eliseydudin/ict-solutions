#include <iostream>
#include <map>
#include <vector>

using map = std::map<int, std::vector<int>>;

int solve(map &m, int root) {
  int count = 1;

  for (auto &child : m[root]) {
    count += solve(m, child);
  }

  return count;
}

int main() {
  int n, k;
  std::cin >> n;

  map input;
  for (int i = 0; i < n; i++) {
    int a, b;
    std::cin >> a >> b;
    input[b].push_back(a);
  }

  std::cin >> k;
  std::cout << solve(input, k) << std::endl;

  return 0;
}
