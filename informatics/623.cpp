#include <cmath>
#include <iostream>

int main() {
  int long long n;
  std::cin >> n;
  long long i = 2;

  while (i <= sqrt(n))
    if (n % i == 0) {
      std::cout << i;
      n = n / i;
      if (n > 1) std::cout << '*';
    } else
      i = i + 1;

  if (n > 1) std::cout << n;

  return 0;
}
