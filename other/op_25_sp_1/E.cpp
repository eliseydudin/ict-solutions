/*
 * NO WORKY
 */

#include <iostream>
#include <queue>
#include <vector>

const int BIG_NUMBER = 2005;
std::vector<std::vector<std::vector<int>>> adjacency(
    BIG_NUMBER, std::vector<std::vector<int>>(BIG_NUMBER, std::vector<int>()));
std::vector<bool> visited(BIG_NUMBER);
std::vector<int> vertices(BIG_NUMBER);
std::vector<std::vector<int>> components(BIG_NUMBER* BIG_NUMBER + BIG_NUMBER);
std::vector<bool> queue_visited(BIG_NUMBER* BIG_NUMBER + BIG_NUMBER);
int comp, cnt;
int n, k;

void out(int res) {
  if (res == -1) {
    std::cout << -1 << std::endl;
  } else {
    std::cout << res / 2 << std::endl;
  }
  exit(0);
}

void dfs(int col, int x) {
  if (visited[x]) return;
  visited[x] = true;
  ++cnt;
  vertices[cnt] = x;

  for (int neighbor : adjacency[col][x]) {
    dfs(col, neighbor);
  }
}

struct Vertex {
  int x, d;
};

int main() {
  std::cin >> n >> k;
  for (int i = 1; i <= k; ++i) {
    int m;
    std::cin >> m;
    for (int j = 1; j <= m; ++j) {
      int x, y;
      std::cin >> x >> y;
      adjacency[i][x].push_back(y);
      adjacency[i][y].push_back(x);
    }
  }

  if (n == 1) out(0);

  comp = n;
  for (int i = 1; i <= k; ++i) {
    std::fill(visited.begin(), visited.end(),
              false);  // Reset visited for each component
    for (int j = 1; j <= n; ++j) {
      if (!visited[j]) {
        cnt = 0;
        dfs(i, j);
        if (cnt > 1) {
          ++comp;
          for (int h = 1; h <= cnt; ++h) {
            components[comp].push_back(vertices[h]);
            components[vertices[h]].push_back(comp);
          }
        }
      }
    }
  }

  std::queue<Vertex> q;
  q.push({1, 0});
  queue_visited[1] = true;

  while (!q.empty()) {
    Vertex current = q.front();
    q.pop();

    for (int neighbor : components[current.x]) {
      if (!queue_visited[neighbor]) {
        q.push({neighbor, current.d + 1});
        queue_visited[neighbor] = true;
        if (neighbor == n) out(current.d + 1);
      }
    }
  }

  out(-1);
}
