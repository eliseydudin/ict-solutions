#include <iostream>

int main() {
  std::string s, t;
  int n, m, i, j, k, d[256];

  std::cin >> s >> t;

  n = s.size();
  m = t.size();

  for (i = 0; i < 256; ++i) d[i] = m;

  for (i = 0; i < m - 1; ++i) d[(unsigned)t[i]] = m - i - 1;

  i = m - 1;

  do {
    j = m - 1;
    k = i;
    while (j >= 0 && t[j] == s[k]) {
      j--;
      k--;
    }
    if (j < 0) std::cout << k + 1 << ' ';
    i += d[s[i]];
  } while (i < n);

  std::cout << std::endl;

  return 0;
}
