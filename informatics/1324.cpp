#include <iostream>
#include <vector>

std::vector<int> z_function(std::string s) {
  int n = s.size();
  std::vector<int> z(n);
  int l = 0, r = 0;

  for (int i = 1; i < n; i++) {
    if (i < r) z[i] = std::min(r - i, z[i - l]);

    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;

    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}

int main() {
  std::string str;
  std::cin >> str;
  auto st = z_function(str);

  std::cout << str.size() << ' ';
  for (int i = 1; i < str.size(); i++) std::cout << st[i] << ' ';

  std::cout << std::endl;

  return 0;
}
