#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::string ans = "YES";
  std::vector<std::vector<int> > g(n, std::vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    std::vector<int> lst(n);
    for (int j = 0; j < n; j++) {
      std::cin >> lst[j];
      g[i][j] = lst[j];
    }
  }
  for (int h = 0; h < n; h++) {
    for (int k = 0; k < n; k++) {
      if (g[h][k] != g[k][h]) ans = "NO";
      if (g[h][h] != 0) ans = "NO";
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
