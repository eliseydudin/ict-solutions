#include <iostream>
#include <map>

int main() {
  size_t n, k;
  std::string line;

  std::map<char, int> matrix, keywords;
  std::cin >> n >> k;

  for (size_t i = 0; i < n; ++i) {
    std::cin >> line;
    for (auto symbol : line) {
      ++matrix[symbol];
    }
  }

  for (size_t i = 0; i < k; ++i) {
    std::cin >> line;
    for (auto symbol : line) {
      ++keywords[symbol];
    }
  }

  for (auto& symbol_counter : keywords) {
    matrix[symbol_counter.first] -= symbol_counter.second;
  }

  for (auto& symbol_counter : matrix) {
    while (symbol_counter.second > 0) {
      std::cout << symbol_counter.first;
      --symbol_counter.second;
    }
  }

  std::cout << std::endl;

  return 0;
}
