#include <iostream>
using namespace std;
int main() {
  int n, a;
  cin >> n;

  int max1 = 0, max2 = 0, min1 = 0, min2 = 0;

  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a >= max1) {
      max2 = max1;
      max1 = a;
    } else if (a >= max2)
      max2 = a;
    if (a <= min1) {
      min2 = min1;
      min1 = a;
    } else if (a <= min2)
      min2 = a;
  }

  if (n == 2) {
    cout << min1 + max2 << ' ' << min2 + max1 << endl;
  } else if (max1 * max2 > min1 * min2) {
    cout << max2 << ' ' << max1 << endl;
  } else {
    cout << min1 << ' ' << min2 << endl;
  }

  return 0;
}
