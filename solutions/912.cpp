#include <iostream>
#include <map>
using u64 = unsigned long long;

u64 solve(u64 n, std::map<u64, u64> &mp) {
  if (mp.find(n) != mp.end()) return mp[n];

  mp[n] = solve(n - 1, mp) + solve(n - 2, mp) + solve(n - 3, mp);
  return mp[n];
}

u64 solve(u64 n) {
  std::map<u64, u64> mp;
  mp[1] = 2;
  mp[2] = 4;
  mp[3] = 7;
  return solve(n, mp);
}

int main() {
  std::ios::sync_with_stdio(0);
  u64 n;
  std::cin >> n;
  std::cout << solve(n) << std::endl;

  return 0;
}
