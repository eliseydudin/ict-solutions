#include <iostream>

int solve(std::string &input, int index, int count) {
  if (index == input.size()) {
    return count;
  }

  if (isdigit(input[index])) {
    count += 1;
  }

  return solve(input, ++index, count);
}

int main() {
  std::string input;
  std::getline(std::cin, input);
  std::cout << solve(input, 0, 0) << std::endl;
  return 0;
}
