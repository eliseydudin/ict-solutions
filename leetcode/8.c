#include <ctype.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

int myAtoi(char* s) {
  if (isspace(*s)) {
    while (isspace(*s++));
    s--;
  }

  char sign = 1;
  int64_t result = 0;
  int index = 0;
  char ch;

  while ((ch = *(s + index))) {
    if (ch == '-' && index == 0) {
      sign = -1;
      index++;
      continue;
    } else if (ch == '+' && index == 0) {
      index++;
      continue;
    }

    if (isdigit(ch)) {
      result = result * 10 + ch - '0';
      if (result * sign < INT_MIN) {
        return INT_MIN;
      } else if (result * sign > INT_MAX) {
        return INT_MAX;
      }
    } else {
      break;
    }

    index++;
  }

  return result * sign;
}

int main() {
  char buffer[20];
  fgets(buffer, 20, stdin);

  printf("%d\n", myAtoi(buffer));
  return 0;
}
