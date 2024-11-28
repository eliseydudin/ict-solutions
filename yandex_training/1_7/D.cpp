#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<std::tuple<int, int, int>> events;

  for (int i = 0; i < n; ++i) {
    int nowin, nowout;
    std::cin >> nowin >> nowout;

    if (nowout - nowin < 5) {
      continue;
    }

    events.emplace_back(nowin, -1, i);
    events.emplace_back(nowout - 5, 1, i);
  }

  sort(events.begin(), events.end());

  if (events.empty()) {
    std::cout << "0 10 20" << std::endl;
  } else if (events.size() == 2) {
    std::cout << 1 << " " << std::get<0>(events[0]) << " "
              << std::get<0>(events[0]) + 10 << std::endl;
  } else {
    int best = 0;
    int first_best = 0, second_best = 0;
    std::set<int> first_ad;

    for (size_t i = 0; i < events.size(); ++i) {
      auto event1 = events[i];
      if (std::get<1>(event1) == -1) {
        first_ad.insert(std::get<2>(event1));
        if (first_ad.size() > best) {
          best = first_ad.size();
          first_best = std::get<0>(event1);
          second_best = std::get<0>(event1) + 5;
        }
      }

      int second_ad_cnt = 0;

      for (size_t j = i + 1; j < events.size(); ++j) {
        auto event2 = events[j];
        if (std::get<1>(event2) == -1 &&
            first_ad.find(std::get<2>(event2)) == first_ad.end()) {
          second_ad_cnt++;
        }
        if (std::get<0>(event2) - 5 >= std::get<0>(event1) &&
            first_ad.size() + second_ad_cnt > best) {
          best = first_ad.size() + second_ad_cnt;
          first_best = std::get<0>(event1);
          second_best = std::get<0>(event2);
        }
        if (std::get<1>(event2) == 1 &&
            first_ad.find(std::get<2>(event2)) == first_ad.end()) {
          second_ad_cnt--;
        }
      }

      if (std::get<1>(event1) == 1) {
        first_ad.erase(std::get<2>(event1));
      }
    }

    std::cout << best << " " << first_best << " " << second_best << std::endl;
  }

  return 0;
}
