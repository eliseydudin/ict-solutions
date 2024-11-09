/*

You are given a positive integer 𝑥. Check whether the number 𝑥 is representable
as the sum of the cubes of two positive integers.

Formally, you need to check if there are two integers 𝑎 and 𝑏 (1≤𝑎,𝑏) such that
𝑎3+𝑏3=𝑥.

For example, if 𝑥=35, then the numbers 𝑎=2 and 𝑏=3 are suitable (23+33=8+27=35).
If 𝑥=4, then no pair of numbers 𝑎 and 𝑏 is suitable.

INPUT
The first line contains one integer 𝑡 (1≤𝑡≤100) — the number of test cases. Then
𝑡 test cases follow.

Each test case contains one integer 𝑥 (1≤𝑥≤1012).

Please note, that the input for some test cases won't fit into 32-bit integer
type, so you should use at least 64-bit integer type in your programming
language.

OUTPUT
For each test case, output on a separate line:

"YES" if 𝑥 is representable as the sum of the cubes of two positive integers.
"NO" otherwise.
You can output "YES" and "NO" in any case (for example, the strings yEs, yes,
Yes and YES will be recognized as positive).
*/

#include <cmath>
#include <iostream>

bool solve(uint64_t n) {
  uint64_t lo = 1, hi = (uint64_t)cbrt(n);
  while (lo <= hi) {
    uint64_t curr = (lo * lo * lo + hi * hi * hi);
    if (curr == n) return true;
    if (curr < n)
      lo++;
    else
      hi--;
  }
  return false;
}

int main() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    uint64_t k;
    std::cin >> k;
    std::cout << (solve(k) ? "YES\n" : "NO\n");
  }

  return 0;
}
