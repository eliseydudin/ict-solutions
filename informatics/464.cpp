#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> b;
  std::vector<std::vector<int> > g(n, std::vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    std::vector<int> lst(n);
    for (int j = 0; j < n; j++) {
      std::cin >> lst[j];
      g[i][j] = lst[j];
    }
  }
  for (int h = 0; h < n; h++) {
    for (int k = h; k < n; k++) {
      if (g[h][k] == 1) {
        b.push_back(h + 1);
        b.push_back(k + 1);
      }
    }
  }
  for (int ht = 0; ht < b.size() - 1; ht += 2)
    std::cout << b[ht] << " " << b[ht + 1] << "\n";

  return 0;
}
