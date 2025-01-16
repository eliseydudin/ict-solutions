/* 95 points */

#include <iostream>

int main() {
  int timer, len_lesson, len_break, lessons;
  std::cin >> timer >> len_lesson >> len_break >> lessons;

  timer -= 90;

  if (timer < 0 ||
      (timer >= len_lesson * lessons + len_break * (lessons - 1)) ||
      (timer % (len_lesson + len_break) >= len_lesson - 1))
    std::cout << -1 << std::endl;
  else
    std::cout << (timer / (len_lesson + len_break)) + 1 << std::endl;

  return 0;
}
