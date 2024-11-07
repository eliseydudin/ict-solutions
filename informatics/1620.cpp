#include <algorithm>
#include <iostream>
#include <vector>

bool hook(std::vector<int> arr, int m, int r, int c) {
  auto h = 0, u = 0;
  for (int i = 0; i < arr.size(); i++) {
    u--;
    if (u < 1 and arr[i] <= m) {
      h++;
      u = c;
    }
  }

  return (h >= r);
}

int main() {
  std::ios::sync_with_stdio(0);

  int n, r, c;
  std::cin >> n >> r >> c;

  std::vector<int> heights(n);
  for (auto &el : heights) std::cin >> el;

  std::sort(heights.begin(), heights.end());

  std::vector<int> silly;
  for (int i = 0; i < heights.size() - c + 1; i++) {
    silly.push_back(heights[i + c - 1] - heights[i]);
  }

  if (r <= 1) {
    std::cout << *std::min(silly.begin(), silly.end()) << std::endl;
    return 0;
  }

  int leg = -1, reg = *(heights.end() - 1) - heights[0];

  while (leg + 1 != reg) {
    int m = (leg + reg) / 2;
    if (hook(silly, m, r, c))
      reg = m;
    else
      leg = m;
  }

  std::cout << reg << std::endl;

  return 0;
}
