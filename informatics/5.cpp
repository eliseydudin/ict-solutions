// NO WORKY

#include <climits>
#include <iostream>
#include <set>

int main() {
  int n, finish, start;
  std::set<std::pair<int, int>> adjacent;
  std::cin >> n >> start >> finish;
  start--;
  finish--;

  int matrix[n][n], distance[n];
  bool visited[n];

  for (int i = 0; i < n; ++i) {
    distance[i] = INT_MAX;
    visited[i] = true;
    for (int j = 0; j < n; ++j) {
      std::cin >> matrix[i][j];
      if (matrix[i][j] < 0) matrix[i][j] = INT_MAX;
    }
  }

  distance[start] = 0;
  adjacent.insert(std::make_pair(0, start));

  while (!adjacent.empty()) {
    int i = adjacent.begin()->second;
    visited[i] = false;
    adjacent.erase(adjacent.begin());

    for (int j = 0; j < n; ++j)
      if (visited[j] && distance[j] > distance[i] + matrix[i][j]) {
        adjacent.erase(std::make_pair(distance[j], j));
        distance[j] = distance[i] + matrix[i][j];
        adjacent.insert(std::make_pair(distance[j], j));
      }
  }

  if (distance[finish] < INT_MAX) {
    std::cout << distance[finish] << std::endl;
  } else {
    std::cout << -1 << std::endl;
  }
  return 0;
}
