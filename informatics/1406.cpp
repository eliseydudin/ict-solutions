#include <climits>
#include <iostream>
#include <vector>

std::vector<int> letter_count(std::string &str) {
  std::vector<int> counter(CHAR_MAX, 0);
  for (auto &el : str) {
    counter[el]++;
  }

  return counter;
}

int main() {
  std::string str1, str2;
  std::cin >> str1 >> str2;

  auto counter1 = letter_count(str1);
  auto counter2 = letter_count(str2);

  for (int i = 0; i < counter1.size(); i++) {
    if (counter1[i] != counter2[i]) {
      std::cout << "NO" << std::endl;
      return 0;
    }
  }

  std::cout << "YES" << std::endl;
  return 0;
}
