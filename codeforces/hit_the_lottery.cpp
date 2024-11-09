/*

Allen has a LOT of money. He has 𝑛 dollars in the bank. For security reasons, he
wants to withdraw it in cash (we will not disclose the reasons here). The
denominations for dollar bills are 1, 5, 10, 20, 100. What is the minimum number
of bills Allen could receive after withdrawing his entire balance?

INPUT
The first and only line of input contains a single integer 𝑛 (1≤𝑛≤109).

OUTPUT
Output the minimum number of bills that Allen could receive.
*/

#include <iostream>

const int arr[] = {100, 20, 10, 5, 1};

int main() {
  int n;
  std::cin >> n;
  int count = 0;

  for (auto elem : arr) {
    int a = n / elem;
    n -= a * elem;
    count += a;
  }

  std::cout << count << std::endl;

  return 0;
}
