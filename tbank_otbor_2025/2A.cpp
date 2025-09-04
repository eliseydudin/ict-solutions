#include <climits>  // IWYU pragma: keep
#include <iostream>
#include <vector>

int main() {
  int64_t n;
  std::cin >> n;
  std::vector<int64_t> dist(n), count(n);

  for (auto &el : dist) {
    std::cin >> el;
  }

  for (auto &el : count) {
    std::cin >> el;
  }

  int64_t min_count = INT64_MAX, sol = -1;

  for (int64_t i = 0; i < n; i++) {
    int64_t current = 0;

    for (int64_t j = 0; j < n; j++) {
      if (j == i) continue;
      current += std::abs(dist[j] - dist[i]) * count[j];
    }

    if (current < min_count) {
      min_count = current;
      sol = i;
    }
  }

  std::cout << ++sol << std::endl;

  return 0;
}
