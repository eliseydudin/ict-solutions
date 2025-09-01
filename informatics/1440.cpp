#include <climits>
#include <iostream>

int main() {
  int n, first_max = INT_MIN, second_max = INT_MIN;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    int input;
    std::cin >> input;

    if (input > first_max) {
      second_max = first_max;
      first_max = input;
    } else if (input != first_max && input > second_max) {
      second_max = input;
    }
  }

  std::cout << second_max << std::endl;

  return 0;
}
