#include <algorithm>
#include <iostream>
#include <set>
#include <tuple>
#include <vector>

const int MONTHS_TO_DAYS[] = {
    0, 31, 0, 30, 31, 30, 31, 30, 31, 30, 31, 30,
};

bool is_leap(int year) {
  return year % 4 || (year % 100 == 0 && year % 400 != 0);
}

int to_days(int day, int month, int year) {
  int days = 0;
  for (int i = 1; i < year; i++) {
    days += is_leap(year) ? 366 : 365;
  }

  for (int i = 1; i < month; i++) {
    if (i == 2) {
      days += is_leap(year) ? 29 : 28;
    } else {
      days += MONTHS_TO_DAYS[i];
    }
  }

  return days + day;
}

std::tuple<int, int, int> add_years(int day, int month, int year, int offset) {
  year += offset;
  return {day, month, year};
}

void solve(std::vector<std::tuple<int, int, int>> events) {
  std::sort(events.begin(), events.end());
  std::set<int> result;
  bool updated = 0;

  for (auto [_, type_e, i_man] : events) {
    if (type_e == 2) {
      result.insert(i_man);
      updated = 1;
    } else {
      if (updated) {
        for (auto el : result) std::cout << el << ' ';
      }
      result.erase(i_man);
    }
  }
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::tuple<int, int, int>> events;

  for (int i = 0; i < n; i++) {
    int d1, m1, y1, d2, m2, y2;
    std::cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;

    int tout = to_days(d2, m2, y2);
    int t18 = to_days(d1, m1, y1 + 18);

    if (t18 < tout) {
      int t80 = to_days(d1, m1, y1 + 80);
      events.push_back({t18, 2, i});
      events.push_back({std::min(tout, t80), 1, i});
    }
  }

  solve(events);
}
