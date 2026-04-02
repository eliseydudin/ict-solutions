#include <array>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

typedef std::vector<std::vector<std::array<int, 3>>> graph_t;

int dijkstra(int n, int m, int cups, graph_t& graph) {
  std::vector<bool> used(n + 1);
  std::priority_queue<std::pair<int, int>> queue;
  queue.push(std::make_pair(0, -1));

  while (!queue.empty()) {
    auto cur = queue.top();
    queue.pop();
    int current_time = -cur.first, from = -cur.second;
    used[from] = true;

    if (current_time > 1440) {
      return 0;
    }

    if (from == n) {
      return current_time;
    }

    for (auto road : graph[from]) {
      if (road[2] >= cups && !used[road[0]]) {
        int tmp = current_time + road[1];
        if (tmp <= 1440) {
          queue.push(std::make_pair(-tmp, -road[0]));
        }
      }
    }
  }

  return 0;
}

int main() {
  int n, m, from, to, time, weight;
  std::cin >> n >> m;

  graph_t graph;
  graph.resize(n + 1);

  if (n == 1) {
    std::cout << 10000000 << std::endl;
    return 0;
  }

  std::set<int> unique_cups;

  for (int i = 0; i < m; ++i) {
    std::cin >> from >> to >> time >> weight;
    int cups = (weight - 3000000) / 100;
    if (cups <= 0) {
      continue;
    }

    graph[from].push_back({to, time, cups});
    graph[to].push_back({from, time, cups});
    unique_cups.insert(cups);
  }

  std::vector<int> unique_cups_vec;
  for (auto cups : unique_cups) {
    unique_cups_vec.push_back(cups);
  }

  int l = 0;
  int r = unique_cups.size() - 1;
  int max_cups = 0;

  while (l <= r) {
    int m = (l + r) / 2;
    int min_time = dijkstra(n, m, unique_cups_vec[m], graph);

    if (min_time == 0) {
      r = m - 1;
    } else {
      l = m + 1;

      if (unique_cups_vec[m] > max_cups) {
        max_cups = unique_cups_vec[m];
      }
    }
  }

  std::cout << max_cups << std::endl;

  return 0;
}
