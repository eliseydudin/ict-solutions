"""
#include <iostream>
#include <map>
using i64 = unsigned long long;

i64 solve(i64 n, std::map<i64, i64> &mp) {
  if (mp.find(n) != mp.end()) {
    return mp[n];
  }

  mp[n] = solve(n - 1, mp) + solve(n - 2, mp);
  return mp[n];
}

i64 solve(i64 n) {
  std::map<i64, i64> mp;
  mp[1] = 2;
  mp[2] = 3;

  return solve(n, mp);
}

int main() {
  std::ios::sync_with_stdio(0);

  i64 n;
  std::cin >> n;
  std::cout << solve(n) << std::endl;

  return 0;
}
"""


def main(): ...


if __name__ == "__main__":
    main()
