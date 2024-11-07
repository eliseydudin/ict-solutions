#include <iostream>
#include <vector>

bool *used;
std::vector<int> *g;

int dfs(int V) {
  used[V] = true;
  int cnt = 1;
  for (auto i : g[V]) {
    if (!used[i]) {
      cnt += dfs(i);
    }
  }

  return cnt;
}
int main() {
  int n, k, v;
  std::cin >> n >> v;
  v--;
  used = new bool[n];

  for (int i = 0; i < n; i++) used[i] = false;

  g = new std::vector<int>[n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> k;
      if (k == 1) {
        g[i].push_back(j);
      }
    }
  }

  std::cout << dfs(v) << std::endl;

  return 0;
}
