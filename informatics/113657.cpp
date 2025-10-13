#include <iostream>

void solve(std::string &input, int index) {
  if (index < 0) {
    return;
  }

  char current = input[index];
  if (current == '(') {
    std::cout << ')';
  } else {
    std::cout << current;
  }

  solve(input, --index);
}

int main() {
  std::string input;
  std::getline(std::cin, input);

  std::cout << input;
  solve(input, input.size() - 1);
  std::cout << std::endl;

  return 0;
}
