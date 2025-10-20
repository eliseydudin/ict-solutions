// 50 points
#include <cmath>
#include <iostream>

int main() {
  int first_count, second_count;
  std::cin >> first_count >> second_count;
  char default_ch = 'B', secondary_ch = 'G';

  if (std::ceil((float)(std::max(first_count, second_count))) / 2 >
      std::min(first_count, second_count)) {
    std::cout << "NO SOLUTION" << std::endl;
    return 0;
  }

  if (first_count < second_count) {
    std::swap(default_ch, secondary_ch);
    std::swap(first_count, second_count);
  }

  while (first_count > 0 || second_count > 0) {
    if (first_count > 1 && second_count > 1) {
      std::cout << default_ch << secondary_ch;
      first_count--;
      second_count--;
    } else if (second_count == 1 && first_count != second_count) {
      std::cout << default_ch;
      first_count--;
    } else {
      std::cout << secondary_ch << default_ch;
      first_count--;
      second_count--;
    }
    // std::cout << '\n' << first_count << ' ' << second_count << '\n';
  }

  std::cout << std::endl;

  // assert(first_count == 0);
  // assert(second_count == 0);

  return 0;
}
