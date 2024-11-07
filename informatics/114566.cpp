#include <iostream>
using namespace std;

void sort(int64_t &a, int64_t &b, int64_t &c) {
  if (a > b) swap(a, b);
  if (b > c) swap(b, c);
  if (a > b) swap(a, b);
}

int main() {
  ios::sync_with_stdio(false);
  int64_t a, b, c;
  cin >> a >> b >> c;
  sort(a, b, c);

  int64_t minresult;
  if (a + 1 == b && b + 1 == c)
    minresult = 0;
  else if (a + 2 == b || b + 2 == c)
    minresult = 1;
  else
    minresult = 2;
  int64_t maxresult = 0;

  maxresult = max(maxresult, b - a - 1);
  maxresult = max(maxresult, c - b - 1);
  cout << minresult << '\n' << maxresult << endl;

  return 0;
}
