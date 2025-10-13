#include <iostream>

int solve(std::string &source, int index) {
  if (index > source.size()) {
    return source[0] - '0';
  }

  int current = source[index] - '0';
  return std::max(current, solve(source, index + 1));
}

int main() {
  std::string input;
  std::getline(std::cin, input);
  std::cout << solve(input, 0) << std::endl;

  return 0;
}
