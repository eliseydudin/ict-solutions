"""
this code doesn't work due to the size of ints :(

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


def solve(m: int, cache: dict[int, int]) -> int:
    data = cache.get(m)
    if data is not None:
        return data

    data = solve(m - 1, cache) + solve(m - 2, cache)
    cache[m] = data

    return data


def main():
    n = int(input())
    cache = {1: 2, 2: 3}

    print(solve(n, cache))


if __name__ == "__main__":
    main()
