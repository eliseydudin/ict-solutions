#include <iostream>

void solve(std::string &input, int index) {
  if (input.size() == index) {
    return;
  }

  std::cout << input[index];
  if (index < input.size() / 2) {
    if (input.size() % 2 == 0 && index == input.size() / 2 - 1) {
      //
    } else {
      std::cout << '(';
    }
  } else if (input.size() - 1 != index) {
    std::cout << ')';
  } else {
    std::cout << std::endl;
  }

  solve(input, ++index);
}

int main() {
  std::string input;
  std::getline(std::cin, input);
  solve(input, 0);

  return 0;
}
