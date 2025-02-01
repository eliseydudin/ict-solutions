#include <iostream>
#include <vector>

typedef long long i64;

i64 solve(i64 left, i64 right, std::vector<i64> &range) {
  left--;
  right--;

  i64 answer = range[left];
  i64 index = left;

  for (i64 i = left; i <= right; i++) {
    if (range[i] > answer) {
      index = i;
      answer = range[i];
    }
  }

  return index + 1;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<i64> data(n);
  for (auto &el : data) std::cin >> el;

  int k;
  std::cin >> k;

  for (int i = 0; i < k; i++) {
    i64 left, right;
    std::cin >> left >> right;
    std::cout << solve(left, right, data) << ' ';
  }

  return 0;
}
