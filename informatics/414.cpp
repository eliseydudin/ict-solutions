/* TODO */

#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> m >> n;
  std::vector<int> deer(m, 0), elfs(n, 0);
  for (auto &el : deer) std::cin >> el;
  for (auto &el : elfs) std::cin >> el;

  int left = 0, right = m;

  while (left <= right) {
    int mid = (left + right) / 2;
  }

  return 0;
}
