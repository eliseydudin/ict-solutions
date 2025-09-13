#include <iostream>

int main() {
  std::string s;
  long long k;
  std::cin >> s >> k;

  long long num = (k - 1) / s.length();
  long long char_i = (k - 1) % s.length();
  long long index = (char_i + num) % s.length();

  std::cout << s[index] << std::endl;

  return 0;
}

// abcd 5
// abcd bcda cdab dabc abcd
// b

// abcd 17
// abcd bcda cdab dabc abcd
