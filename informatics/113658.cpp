#include <iostream>

void solve(std::string &input, int index) {
  if (index == input.size()) {
    std::cout << std::endl;
    return;
  }

  char current = input[index];
  char mirror = input[input.size() - 1 - index];

  if (current != mirror || (index == input.size() - 1 - index)) {
    std::cout << current;
  }

  solve(input, ++index);
}

int main() {
  std::string input;
  std::getline(std::cin, input);
  solve(input, 0);

  return 0;
}
