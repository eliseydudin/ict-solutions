/* спасибо колянчику */

#include <iostream>

int main() {
  int n = 0, in = 0, max = -1, s = 0;

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> in;
    s += in;
    if (in > max) {
      max = in;
    }
  }

  if (s - max < max) {
    std::cout << max - (s - max) << std::endl;
  } else {
    std::cout << s << std::endl;
  }
  return 0;
}
