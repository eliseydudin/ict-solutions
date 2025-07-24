#include <iostream>
#include <vector>

int main() {
  int l, n, m;
  std::cin >> l >> n >> m;
  std::vector<int> positions(l + 2, 0);

  for (auto i = 0; i < n; i++) {
    int l, r;
    std::cin >> l >> r;

    for (int j = l; j <= r; j++) {
      positions[j]++;
    }
  }

  for (int i = 0; i < m; i++) {
    int input;
    std::cin >> input;

    std::cout << positions[input] << '\n';
  }
}
