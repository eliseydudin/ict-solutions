/*
 * NO WORKY
 * TL test 10
 */

#include <iostream>

int solve(const std::string& s, int k, int n) {
  int count = 0;

  for (int start = 0; start < n; ++start) {
    for (int end = start; end < n; ++end) {
      std::string substring = s.substr(start, end - start + 1);
      int changes_needed = 0;

      int left = 0;
      int right = substring.length() - 1;
      while (left < right) {
        if (substring[left] != substring[right]) {
          changes_needed++;
        }
        left++;
        right--;

        if (changes_needed > k) {
          break;
        }
      }

      if (changes_needed <= k) {
        count++;
      }
    }
  }

  return count;
}

int main() {
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;

  std::cout << solve(s, k, n) << std::endl;

  return 0;
}
