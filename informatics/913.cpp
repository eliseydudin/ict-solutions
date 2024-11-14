#include <iostream>
#include <vector>

struct pair {
  int first, second;
};

int main() {
  int n;
  std::cin >> n;
  std::vector<pair> array(n + 1);
  array[1].first = array[1].second = 1;

  for (int i = 2; i <= n; i++) {
    array[i].first = array[i - 1].second;
    array[i].second = array[i - 1].first + array[i - 1].second;
  }

  std::cout << (array[n].first + array[n].second) << std::endl;

  return 0;
}
