#include <iostream>
#include <vector>

int main() {
  int n, bridge;
  std::cin >> n;
  std::vector<std::vector<int>> matrix(n, std::vector<int>(0));
  std::vector<int> colors(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> bridge;
      if (bridge) matrix[i].push_back(j);
    }
  }

  for (auto& el : colors) std::cin >> el;
  int bad_bridges = 0;

  for (int i = 0; i < n; i++) {
    auto island_color = colors[i];
    for (auto bridge : matrix[i]) {
      if (colors[bridge] != island_color) bad_bridges++;
    }
  }

  std::cout << bad_bridges / 2 << std::endl;

  return 0;
}
