#include <limits.h>
#include <stdint.h>
#include <stdio.h>

int reverse(int x) {
  int64_t result = 0;
  char sign = 1;

  if (x == INT_MIN) {
    return 0;
  } else if (x < 0) {
    sign = -1;
    x *= -1;
  }

  while (x > 0) {
    if (result * sign * 10 < INT_MIN) {
      return 0;
    } else if (result * sign * 10 > INT_MAX) {
      return 0;
    }

    result = result * 10 + x % 10;
    x /= 10;
  }

  return result * sign;
}

int main() {
  int x;
  scanf("%d", &x);
  printf("%d\n", reverse(x));

  return 0;
}
