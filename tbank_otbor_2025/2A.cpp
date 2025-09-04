#include <climits>  // IWYU pragma: keep
#include <iostream>
#include <vector>

int main() {
  long long n;
  std::cin >> n;
  std::vector<long long> dist(n), count(n);

  for (auto &el : dist) {
    std::cin >> el;
  }

  for (auto &el : count) {
    std::cin >> el;
  }

  long long min_count = LONG_LONG_MAX, sol = -1;

  for (long long i = 0; i < n; i++) {
    long long current = 0;

    for (long long j = 0; j < n; j++) {
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
