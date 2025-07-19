#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> ships(n * m);
  for (auto &el : ships) std::cin >> el;
  std::sort(ships.begin(), ships.end());

  int max = ships.back();

  int k, count = 0;
  std::cin >> k;
  std::vector<int> weights(k);
  for (auto &el : weights) std::cin >> el;
  std::sort(weights.rbegin(), weights.rend());

  for (auto &el : weights) {
    if (el > max) continue;
    int back = ships.back();

    if (back >= el) {
      count++;
      ships.pop_back();
    }
  }

  std::cout << count << std::endl;

  return 0;
}
