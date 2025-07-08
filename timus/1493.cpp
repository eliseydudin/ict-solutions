#include <iostream>

inline bool is_lucky(int n) {
  return n / 100000 + (n / 10000 % 10) + (n / 1000 % 10) ==
         (n / 100 % 10) + (n / 10 % 10) + n % 10;
}

int main() {
  int input;
  std::cin >> input;

  int plus1 = input + 1, minus1 = input - 1;
  if (is_lucky(plus1) || is_lucky(minus1)) {
    std::cout << "Yes";
  } else {
    std::cout << "No";
  }

  std::cout << std::endl;

  return 0;
}
