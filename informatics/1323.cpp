#include <iostream>
#include <vector>

std::vector<int> prefix_function(std::string s) {
  int n = (int)s.length();
  std::vector<int> pi(n);

  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];

    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

int main(int argc, char **argv) {
  std::string str;
  std::cin >> str;

  for (auto i : prefix_function(str)) std::cout << i << " ";

  std::cout << "\n";

  return 0;
}
