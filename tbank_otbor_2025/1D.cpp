#include <iostream>

using pos = std::pair<int, int>;

inline pos s2pos(std::string a) { return {a[0] - 'a' + 1, a[1] - '0'}; }

bool solve(std::string start, std::string finish) {
  auto start_pos = s2pos(start), end_pos = s2pos(finish);

  // eg e2 & e5
  if (start_pos.first == end_pos.first) {
    int dist = end_pos.second - start_pos.second;

    if (dist == 2 || (dist == 3 && start_pos.second == 2)) {
      return true;
    } else if (dist == 1) {
      return false;
    }
  }

  if (start_pos.second == 7) {
    start_pos.second++;
    // same line
    if (start_pos.second == end_pos.second ||
        start_pos.first == end_pos.first) {
      return true;
    }

    // diagonal movement
    if (std::abs(start_pos.first - end_pos.first) ==
        std::abs(start_pos.second - end_pos.second)) {
      return true;
    }

    pos diff = {std::abs(start_pos.first - end_pos.first),
                std::abs(start_pos.second - end_pos.second)};

    if ((diff.first == 2 && diff.second == 1) ||
        (diff.first == 1 && diff.second == 2))
      return true;
  }

  return false;
}

int main() {
  int n;
  std::cin >> n;
  std::string start, finish;

  for (int i = 0; i < n; i++) {
    std::cin >> start >> finish;
    if (solve(start, finish)) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
  std::cout << std::endl;

  return 0;
}
