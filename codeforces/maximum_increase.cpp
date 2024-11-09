/*
You are given array consisting of n integers. Your task is to find the maximum
length of an increasing subarray of the given array.

A subarray is the sequence of consecutive elements of the array. Subarray is
called increasing if each element of this subarray strictly greater than
previous.

INPUT
The first line contains single positive integer n (1 ≤ n ≤ 105) — the number of
integers.

The second line contains n positive integers a1, a2, ..., an (1 ≤ ai ≤ 109).

OUTPUT
Print the maximum length of an increasing subarray of the given array.
*/

#include <iostream>

int main() {
  int n, l, b = 1, mx = 1;
  std::cin >> n >> l;

  for (int i = 1; i < n; i++) {
    int a;
    std::cin >> a;
    if (a > l)
      b++;
    else {
      mx = std::max(mx, b);
      b = 1;
    }
    l = a;
  }

  std::cout << std::max(mx, b) << std::endl;
}
