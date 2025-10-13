#include <iostream>

void solve(std::string &input, int index) {
  if (index == input.size()) {
    return;
  }
  std::cout << input[index];
  if (index != input.size() - 1) {
    std::cout << '*';
  } else {
    std::cout << std::endl;
  }

  solve(input, index + 1);
}

int main() {
  std::string input;
  std::getline(std::cin, input);
  solve(input, 0);

  return 0;
}
