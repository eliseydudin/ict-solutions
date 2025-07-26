#include <iostream>
#include <vector>

struct node_data {
  int in = 0, out = 0;
};

int main() {
  int n;
  std::cin >> n;
  std::vector<node_data> data(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int input;
      std::cin >> input;
      if (input == 0) continue;

      data[i].out++;
      data[j].in++;
    }
  }

  std::vector<int> in, out;
  for (int i = 0; i < n; i++) {
    auto &el = data[i];
    if (el.in == 0) in.push_back(i);
    if (el.out == 0) out.push_back(i);
  }

  std::cout << in.size() << std::endl;
  for (auto &el : in) std::cout << ++el << '\n';
  std::cout << out.size() << std::endl;
  for (auto &el : out) std::cout << ++el << '\n';

  return 0;
}
