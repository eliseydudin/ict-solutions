/* TODO */

#include <cstdint>
#include <iostream>
#include <utility>

const uint32_t MAX = 1000000000;

using pos_t = std::pair<uint32_t, uint32_t>;

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

inline bool inverted(bool orig, bool invert) {
  if (invert)
    return orig;
  else
    return !orig;
}

uint32_t actual_bin_search(uint32_t left, uint32_t right, uint32_t other,
                           bool is_x) {
  while (left <= right) {
  }
}

pos_t bin_search() {
  pos_t left = {0, 0}, right = {MAX, MAX};
  auto last = left;
  ask(last);  // start;

  while (true) {
    auto realdiff = diff(left, right);
    if (realdiff.first <= 1 && realdiff.second <= 1) {
      break;
    } else if (realdiff.first <= 1) {
      // bin search
    }

    pos_t mid = {(left.first + right.first) / 2,
                 (left.second + right.second) / 2};
    auto res = ask(mid);
    auto pdiff = diff(last, mid);

    if (inverted(pdiff.first < 0, res)) {
      left.first = mid.first;
    } else if (inverted(pdiff.first > 0, res)) {
      right.first = mid.first;
    }

    if (inverted(pdiff.second < 0, res)) {
      left.second = mid.second;
    } else if (inverted(pdiff.second > 0, res)) {
      right.second = mid.second;
    }

    last = mid;
  }

  return left;
}

int main() {
  auto res = bin_search();
  std::cout << "A " << res.first << ' ' << res.second << std::endl;
  return 0;
}
