#include <iostream>

int main() {
  const int seconds[] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6,  6,  6,  7,
                         7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};

  std::string input;
  std::cin >> input;
  int result = 0;

  for (auto ch : input) {
    result += seconds[ch - 'A'];
  }

  std::cout << result << std::endl;

  return 0;
}
