#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
using lll = __int128;

istream& operator>>(istream& in, __int128& a) {
  string s;
  in >> s;
  a = 0;
  if (s == "0") return in;
  for (short i = (s[0] == '-'); i < s.size(); i++) a = a * 10 + (s[i] - '0');
  if (s[0] == '-') a *= -1;
  return in;
}
ostream& operator<<(ostream& out, __int128 a) {
  __int128 b = a;
  if (b < 0) out << '-', b *= -1;
  string s;
  do {
    s.push_back(b % 10 + '0');
    b /= 10;
  } while (b > 0);
  for (int i = s.size() - 1; i >= 0; i--) out << s[i];
  return out;
}
string to_string(__int128 a) {
  string s;
  bool bo = 0;
  if (a < 0) a *= -1, s.push_back('-'), bo = 1;
  do {
    s.push_back(a % 10 + '0');
    a /= 10;
  } while (a > 0);
  for (int i = 0; i < (s.size() - bo) / 2; i++)
    swap(s[i + bo], s[s.size() - i - 1]);
  return s;
}
__int128 stolll(string s) {
  __int128 a = 0;
  if (s == "") return a;
  for (short i = (s[0] == '-'); i < s.size(); i++) a = a * 10 + (s[i] - '0');
  if (s[0] == '-') a *= -1;
  return a;
}

set<vector<int>> results;

template <typename T>
constexpr bool in(const vector<T>& arr, const T v) {
  for (const T& el : arr)
    if (el == v) return true;
  return false;
}

template <typename T>
vector<T> concat_add(const vector<T> arr, const T v) {
  vector<T> nw(arr);
  nw.push_back(v);
  return nw;
}

void rec(int curr, vector<int> claimed) {
  if (curr == 42) results.insert(claimed);
  if (claimed.size() > 10) return;
  if (curr < 49 && !in(claimed, curr + 1))
    rec(curr + 1, concat_add(claimed, curr + 1));
  if (curr > 40 && !in(claimed, curr - 1))
    rec(curr - 1, concat_add(claimed, curr - 1));
  if (curr <= 46 && !in(claimed, curr + 3))
    rec(curr + 3, concat_add(claimed, curr + 3));
  if (curr >= 43 && !in(claimed, curr - 3))
    rec(curr - 3, concat_add(claimed, curr - 3));
}

int main() {
  rec(42, {});
  cout << results.size() << endl;
  for (auto& el : results) {
    for (auto& el1 : el) cout << el1 << ' ';
    cout << endl;
  }
  return 0;
}
