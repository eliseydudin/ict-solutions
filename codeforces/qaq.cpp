/*

"QAQ" is a word to denote an expression of crying. Imagine "Q" as eyes with
tears and "A" as a mouth.

Now Diamond has given Bort a string consisting of only uppercase English letters
of length n. There is a great number of "QAQ" in the string (Diamond is so
cute!).

Bort wants to know how many subsequences "QAQ" are in the string Diamond has
given. Note that the letters "QAQ" don't have to be consecutive, but the order
of letters should be exact.

INPUT
The only line contains a string of length n (1 ≤ n ≤ 100). It's guaranteed that
the string only contains uppercase English letters.

OUTPUT
Print a single integer — the number of subsequences "QAQ" in the string.
*/

#include <iostream>

int main() {
  std::string s;
  std::cin >> s;
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'Q') {
      c += b;
      a++;
    }
    if (s[i] == 'A') {
      b += a;
    }
  }
  std::cout << c << std::endl;
  return 0;
}
