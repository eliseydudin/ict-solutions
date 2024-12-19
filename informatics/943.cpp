#include <iostream>
#include <vector>

/// some really really old code

void print_arr(std::vector<int> arr) {
  for (int elem : arr) std::cout << elem << " ";
  std::cout << "\n";
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> arr(1, 1), copy;

  for (int i = 0; i < n; i++) {
    print_arr(arr);
    copy = arr;
    arr.push_back(1);
    for (int j = 1; j < copy.size(); j++) {
      arr[j] = copy[j] + copy[j - 1];
    }
  }

  return 0;
}
