#include <iostream>
#include <map>
#include <queue>

std::map<std::string, std::string> bfs(std::string start, std::string end) {
  std::queue<std::string> queue;
  std::map<std::string, std::string> used;

  used[start] = start;
  queue.push(start);

  while (!queue.empty()) {
    auto str = queue.front();
    queue.pop();

    auto push = [&](std::string s) {
      if (used[s].empty()) {
        used[s] = str;
        queue.push(s);
      }
    };

    if (str.front() != '9') {
      auto copy = str;
      copy.front()++;
      push(copy);
    }

    if (str.back() != '1') {
      auto copy = str;
      copy.back()--;
      push(copy);
    }

    auto copy = std::string({str[1], str[2], str[3], str[0]});
    push(copy);

    copy = std::string({str[3], str[0], str[1], str[2]});
    push(copy);
  }

  return used;
}

int main() {
  std::string start, end;
  std::cin >> start >> end;

  auto res = bfs(start, end);
  std::vector<std::string> ancestors;

  auto current = end;
  while (current != start) {
    ancestors.push_back(current);
    current = res[current];
  }

  std::cout << start << '\n';
  for (int i = ancestors.size() - 1; i >= 0; i--) {
    std::cout << ancestors[i] << '\n';
  }

  return 0;
}
