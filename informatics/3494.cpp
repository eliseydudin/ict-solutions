#include <iostream>
#include <set>
#include <vector>

const int INF = 2009000999;

void dijkstra(int n, std::vector<std::vector<std::pair<int, int>>>& adjacent,
              std::vector<int>& dist, int target) {
  std::vector<bool> used(n, false);

  dist[target] = 0;
  std::set<std::pair<int, int>> queue;
  queue.insert({0, target});

  while (!queue.empty()) {
    int current_target = queue.begin()->second;
    queue.erase(queue.begin());

    for (auto edge : adjacent[current_target]) {
      int to = edge.first;
      int len = edge.second;

      if (dist[current_target] + len < dist[to]) {
        queue.erase({dist[to], to});
        dist[to] = dist[current_target] + len;
        queue.insert({dist[to], to});
      }
    }
  }
}

int main() {
  int launches, n, m, find_to, left, right, dist;
  std::cin >> launches;

  for (int i = 0; i < launches; i++) {
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> adjacent(n);
    std::vector<int> distance(n, INF);

    for (int j = 0; j < m; j++) {
      std::cin >> left >> right >> dist;
      adjacent[left].push_back({right, dist});
      adjacent[right].push_back({left, dist});
    }

    std::cin >> find_to;

    dijkstra(n, adjacent, distance, find_to);

    for (auto& el : distance) std::cout << el << ' ';
    std::cout << '\n';
  }

  return 0;
}
