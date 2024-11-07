#include <iostream>

int main() {
  std::string s;
  std::cin >> s;

  int res = 0;

  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '0' || s[i] == '6' || s[i] == '9')
      ++res;
    else if (s[i] == '8')
      res += 2;
  }

  std::cout << res << std::endl;
  return 0;
}
