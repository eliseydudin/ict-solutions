/*
During your journey through computer universes, you stumbled upon a very
interesting world. It is a path with 𝑛 consecutive cells, each of which can
either be empty, contain thorns, or a coin. In one move, you can move one or two
cells along the path, provided that the destination cell does not contain thorns
(and belongs to the path). If you move to the cell with a coin, you pick it up.

You want to collect as many coins as possible. Find the maximum number of coins
you can collect in the discovered world if you start in the leftmost cell of the
path.

INPUT
The first line of input contains a single integer 𝑡 (1≤𝑡≤1000) — the number of
test cases. Then the descriptions of the test cases follow.

The first line of each test case contains a single integer 𝑛 (1≤𝑛≤50) — the
length of the path.

The second line of each test case contains a string of 𝑛 characters, the
description of the path. The character '.' denotes an empty cell, '@' denotes a
cell with a coin, and '*' denotes a cell with thorns. It is guaranteed that the
first cell is empty.

OUTPUT
For each test case, output a single integer, the maximum number of coins you can
collect.
*/

#include <iostream>

inline int solve(std::string s) {
  auto count = 0;

  for (auto i = 0; i < s.size(); i++) {
    auto ch = s[i];
    switch (ch) {
      case '@':
        count++;
        break;
      case '*':
        if (i != s.size() - 1 && s[i + 1] == '*') goto end;
      default:
        break;
    };
  }
end:
  return count;
}

int main() {
  int tests;
  std::cin >> tests;

  for (int i = 0; i < tests; i++) {
    int text;
    std::cin >> text;
    std::string inp;
    std::cin >> inp;

    std::cout << solve(inp) << '\n';
  }

  return 0;
}
