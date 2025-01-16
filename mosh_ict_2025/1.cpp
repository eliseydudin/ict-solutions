#include <iostream>

int main() {
  int timer, len_lesson, len_break, lessons;
  std::cin >> timer >> len_lesson >> len_break >> lessons;

  int start_time = 9 * 60;
  int alarm_time = (7 * 60 + 30) + timer;

  for (int i = 1; i <= lessons; ++i) {
    int lesson_start = start_time + (i - 1) * (len_lesson + len_break);
    int lesson_end = lesson_start + len_lesson;
    if (alarm_time >= lesson_start && alarm_time < lesson_end) {
      std::cout << i << '\n';
      return 0;
    }
  }

  std::cout << "-1" << std::endl;
  return 0;
}
