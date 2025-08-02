#include <iostream>
#include <set>
#include <utility>

using field = std::set<std::pair<int, int>>;

void dfs(field &f, std::pair<int, int> coord) {
  f.erase(coord);
  int delta_i[4] = {coord.first - 1, coord.first + 1, coord.first, coord.first},
      delta_j[4] = {coord.second, coord.second, coord.second - 1,
                    coord.second + 1};

  for (int i = 0; i < 4; i++) {
    auto p = std::make_pair(delta_i[i], delta_j[i]);
    if (f.count(p) == 1) dfs(f, p);
  }
}

int main() {
  int n, m, count = 0;
  field f;

  std::cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char inp;
      std::cin >> inp;
      if (inp == '#') f.insert(std::make_pair(i, j));
    }
  }

  while (!f.empty()) {
    auto p = *f.begin();
    dfs(f, p);
    count++;
  }

  std::cout << count << std::endl;

  return 0;
}
