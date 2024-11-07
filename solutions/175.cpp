#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);

  int n, m, i1, i2;
  std::cin >> n >> m;
  std::vector<int> arr(n, 0);

  for (int i = 0; i < m; i++) {
    std::cin >> i1 >> i2;
    arr[i1 - 1] += 1;
    arr[i2 - 1] += 1;
  }

  for (auto &&elem : arr) std::cout << elem << " ";

  return 0;
}
