#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string x, z;

  std::getline(std::cin, x);
  std::getline(std::cin, z);

  std::reverse(x.begin(), x.end());
  std::reverse(z.begin(), z.end());

  std::string repeated_x;
  while (repeated_x.length() < z.length()) {
    repeated_x += x;
  }

  std::vector<char> y;
  size_t i = 0;

  while (i < z.length()) {
    std::string rest = z.substr(i);
    if (repeated_x.find(rest) == 0) {
      break;
    }
    y.push_back(z[i]);
    i++;
  }

  std::reverse(y.begin(), y.end());
  for (char c : y) {
    std::cout << c;
  }

  std::cout << std::endl;

  return 0;
}
