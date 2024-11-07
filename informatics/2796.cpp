#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;
  std::string str = std::to_string(n), res;

  std::vector<std::string> a;
  a.push_back(str);

  while (a.size() < k) {
    str = a[a.size() - 1];
    res = "";

    while (str.size() > 1) {
      int i = 1;
      while (str[0] == str[i]) ++i;

      res += std::to_string(i);
      res += str[0];
      str.erase(0, i);
    }

    if (str.size()) res += "1", res += str[0];
    a.push_back(res);
  }

  std::cout << a[a.size() - 1] << std::endl;

  return 0;
}
