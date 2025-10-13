#include <iostream>

bool solve(int start, int n) {
  if (start > n) {
    return false;
  } else if (start == n) {
    return true;
  }

  return solve(start + 5, n) || solve(start + 3, n);
}

int main() {
  int n;
  std::cin >> n;

  if (solve(1, n)) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  std::cout << std::endl;

  return 0;
}
