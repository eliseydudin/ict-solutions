/*
  NO WORKY
*/

#include <algorithm>
#include <cstdint>
#include <iostream>

// 0 1 2 3 4 5 6 7 8 9 10
int8_t buffer[10];

int main() {
  char input;
  while ((input = std::cin.get())) {
    if (input == '\n') break;
    buffer[input - '0']++;
  }

  std::string output;
  while ((input = std::cin.get())) {
    if (input == '\n') break;
    if (buffer[input - '0']) {
      output += input;
      buffer[input - '0']--;
    }
  }

  if (output.empty()) {
    std::cout << "-1\n";
  } else {
    std::sort(output.rbegin(), output.rend());
    std::cout << output << std::endl;
  }

  return 0;
}
