#include <iostream>
#include <set>
#include <vector>

std::pair<int64_t, char> check_symbol(std::string &from_s, std::string &check_s,
                                      char &c) {
  int64_t count_nomatch = 0;
  char last = ' ';

  for (int64_t i = 0; i < from_s.size(); i++) {
    if (from_s[i] == c && check_s[i] != c && check_s[i] != last) {
      count_nomatch++;
      last = check_s[i];
    }
  }
  return {count_nomatch, last};
}

int main() {
  int64_t n;
  std::string s1, s2;
  std::cin >> n >> s1 >> s2;

  std::set<char> s;
  for (char &c : s1) s.insert(c);
  bool is_spis = true;
  std::vector<std::pair<char, char>> replaces;

  for (char c : s) {
    auto g = check_symbol(s1, s2, c);
    if (g.first >= 2) {
      is_spis = false;
      break;
    } else if (g.first == 1)
      replaces.push_back({c, g.second});
  }
  if (!is_spis) {
    std::cout << "NO" << std::endl;
    return 0;
  }

  std::cout << "YES\n" << replaces.size() << '\n';

  for (auto &el : replaces) std::cout << el.first << ' ' << el.second << '\n';
  std::cout << std::flush;

  return 0;
}
