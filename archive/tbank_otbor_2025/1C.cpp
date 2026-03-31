#include <iostream>
#include <set>

using pos = std::pair<int, int>;

void push_verticies(int i, int j, std::set<pos> &used) {
  for (int n = i + 1; n <= i + 10; n++) {
    for (int m = j + 1; m <= j + 10; m++) {
      if (n > 100 || m > 100) break;
      used.insert({n, m});
    }
  }
}

int main() {
  int n, i, j;
  std::set<pos> used;
  std::cin >> n;

  for (int iter = 0; iter < n; iter++) {
    std::cin >> i >> j;

    push_verticies(i, j, used);
  }

  std::cout << used.size() << std::endl;

  return 0;
}
