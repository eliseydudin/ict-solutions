#include <iostream>

int checked_sub(int src, int a) {
  if (src < a) {
    return checked_sub(src + 26, a);
  } else {
    return src - a;
  }
}

int main() {
  std::string input;
  std::cin >> input;

  int letter0 = checked_sub(input[0] - 'a', 5);
  std::cout << char(letter0 + 'a');

  int prev = input[0] - 'a';

  for (int i = 1; i < input.size(); i++) {
    int letter = input[i] - 'a';
    int new_letter = checked_sub(letter, prev);
    std::cout << char(new_letter + 'a');

    prev += new_letter;
  }

  std::cout << "\n";
}
