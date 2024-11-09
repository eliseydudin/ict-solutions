/*
There was an electronic store heist last night.

All keyboards which were in the store yesterday were numbered in ascending order
from some integer number 𝑥. For example, if 𝑥=4 and there were 3 keyboards in
the store, then the devices had indices 4, 5 and 6, and if 𝑥=10 and there were 7
of them then the keyboards had indices 10, 11, 12, 13, 14, 15 and 16.

After the heist, only 𝑛 keyboards remain, and they have indices 𝑎1,𝑎2,…,𝑎𝑛.
Calculate the minimum possible number of keyboards that have been stolen. The
staff remember neither 𝑥 nor the number of keyboards in the store before the
heist.

INPUT
The first line contains single integer 𝑛 (1≤𝑛≤1000) — the number of keyboards in
the store that remained after the heist.

The second line contains 𝑛 distinct integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤109) — the indices
of the remaining keyboards. The integers 𝑎𝑖 are given in arbitrary order and are
pairwise distinct.

OUTPUT
Print the minimum possible number of keyboards that have been stolen if the
staff remember neither 𝑥 nor the number of keyboards in the store before the
heist.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int count;
  std::cin >> count;
  std::vector<int> silly(count);

  for (auto &el : silly) std::cin >> el;

  int min_a = *min_element(silly.begin(), silly.end());
  int max_a = *max_element(silly.begin(), silly.end());

  int total_needed = max_a - min_a + 1;
  int stolen_count = total_needed - count;

  std::cout << stolen_count << std::endl;

  return 0;
}
