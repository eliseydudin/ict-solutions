#include <stdio.h>

int abs(int a) {
  if (a > 0)
    return a;
  else
    return -a;
}

int main(int argc, char **argv) {
  int num_shirts, num_pants, input;
  scanf("%d", &num_shirts);
  int shirt_colors[num_shirts];

  for (int i = 0; i < num_shirts; i++) {
    scanf("%d", &input);
    shirt_colors[i] = input;
  }

  scanf("%d", &num_pants);
  int pants_colors[num_pants];
  for (int i = 0; i < num_pants; i++) {
    scanf("%d", &input);
    pants_colors[i] = input;
  }

  int c1 = 0, c2 = 0, diff = 2147483647, i = 0, j = 0, num;

  while (i < num_shirts && j < num_pants) {
    num = abs(shirt_colors[i] - pants_colors[j]);

    if (num == 0) {
      c1 = shirt_colors[i];
      c2 = pants_colors[j];
      break;
    }
    if (num < diff) {
      diff = num;
      c1 = shirt_colors[i];
      c2 = pants_colors[j];
    }
    if (shirt_colors[i] < pants_colors[j])
      i++;
    else
      j++;
  }

  printf("%d %d\n", c1, c2);

  return 0;
}
