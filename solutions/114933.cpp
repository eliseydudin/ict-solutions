#include <cstdint>
#include <iostream>
#include <vector>

int main() {
  int64_t a, b, t;

  std::cin >> a >> b >> t;
  std::cout << (a - b) * 2 << std::endl;

  if (!t) return 0;

  std::vector<int64_t> arr;
  int64_t cur = b;

  while (cur <= a) {
    arr.push_back(cur);
    cur++;
  }
  cur -= 2;

  while (cur > b) {
    arr.push_back(cur);
    cur--;
  }

  for (int64_t &el : arr) std::cout << el << ' ';
  std::cout << std::endl;

  return 0;
}
