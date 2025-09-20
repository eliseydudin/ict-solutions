/* TODO */

#include <cstdint>
#include <iostream>
#include <utility>

const int64_t MAX = 1000000000;

using pos_t = std::pair<int64_t, int64_t>;

inline pos_t diff(pos_t old, pos_t newest) {
  return {newest.first - old.first, newest.second - old.second};
}

bool ask(pos_t pos) {
  std::cout << pos.first << ' ' << pos.second << '\n';
  std::cout.flush();

  int num;
  std::cin >> num;

  return bool(num);
}

int64_t bin_search_x() {
  int64_t left = 0, right = MAX;
  pos_t last{0, 0};

  while (left + 1 < right) {
    auto mid = (left + right) / 2;
    pos_t mid_point = {mid, 0};
    auto cdiff = diff(last, mid_point);
    auto res = ask(mid_point);

    // left
    if (cdiff.first >= 0) {
      if (res) {
        left = mid;
      } else {
        right = mid;
      }
    } else if (cdiff.first < 0) {
      // right
      if (res) {
        right = mid;
      } else {
        left = mid;
      }
    } else {
      if (res) {
        left++;
      } else {
        right--;
      }
    }

    last = mid_point;
  }

  return left;
}

int main() {
  ask({0, 0});
  const auto x = bin_search_x();
  std::cout << x << std::endl;

  return 0;
}
