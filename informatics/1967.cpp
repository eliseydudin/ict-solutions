#include <climits>
#include <iostream>
#include <set>
#include <vector>

struct road {
  int time, max_weight;

  road(int time, int max_weight) : time(time), max_weight(max_weight) {}
  road() : time(-1), max_weight(-1) {}
};

struct node_data {
  int time_to = -1;
  int cups = 0;
};

int djikstra(int n, std::vector<std::vector<road>>& graph) {
  std::set<int> visited;
  std::vector<node_data> dist(n, node_data());

  int target = 0;
  dist[target].time_to = 0;
  dist[target].cups = 10000000;

  while (true) {
    auto target_node = dist[target];

    for (int i = 0; i < n; i++) {
      auto rd = graph[target][i];
      if (visited.count(i) == 1 || rd.time == -1) continue;

      auto& i_node = dist[i];
      auto new_cups = std::min(target_node.cups, rd.max_weight);

      if (i_node.time_to == -1 || i_node.cups < new_cups) {
        i_node.time_to = target_node.time_to + rd.time;
        i_node.cups = new_cups;
      }
    }

    visited.insert(target);
    target = INT_MAX;

    for (int i = 0; i < n; i++) {
      auto d = dist[i];
      if (visited.count(i) == 1 || d.time_to == -1) continue;
      if (target == INT_MAX || dist[target].cups > d.cups) target = i;
    }

    if (target == INT_MAX) {
      break;
    }
  }

  return dist[n - 1].cups;
}

int main() {
  int n, m, left, right, minutes, max_weight;
  std::cin >> n >> m;

  std::vector<std::vector<road>> graph(n, std::vector<road>(n, road()));

  for (int i = 0; i < n; i++) {
    std::cin >> left >> right >> minutes >> max_weight;

    auto cups = (max_weight - 3000000) / 100;
    if (cups <= 0) {
      continue;
    }

    graph[left - 1][right - 1] = road(minutes, cups);
    graph[right - 1][left - 1] = road(minutes, cups);
  }

  auto answer = djikstra(n, graph);
  std::cout << answer << std::endl;

  return 0;
}
