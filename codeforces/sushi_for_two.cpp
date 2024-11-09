/*
Arkady invited Anna for a dinner to a sushi restaurant. The restaurant is a bit
unusual: it offers 𝑛 pieces of sushi aligned in a row, and a customer has to
choose a continuous subsegment of these sushi to buy.

The pieces of sushi are of two types: either with tuna or with eel. Let's denote
the type of the 𝑖-th from the left sushi as 𝑡𝑖, where 𝑡𝑖=1 means it is with
tuna, and 𝑡𝑖=2 means it is with eel.

Arkady does not like tuna, Anna does not like eel. Arkady wants to choose such a
continuous subsegment of sushi that it has equal number of sushi of each type
and each half of the subsegment has only sushi of one type. For example,
subsegment [2,2,2,1,1,1] is valid, but subsegment [1,2,1,2,1,2] is not, because
both halves contain both types of sushi.

Find the length of the longest continuous subsegment of sushi Arkady can buy.

INPUT
The first line contains a single integer 𝑛 (2≤𝑛≤100000) — the number of pieces
of sushi.

The second line contains 𝑛 integers 𝑡1, 𝑡2, ..., 𝑡𝑛 (𝑡𝑖=1, denoting a sushi with
tuna or 𝑡𝑖=2, denoting a sushi with eel), representing the types of sushi from
left to right.

It is guaranteed that there is at least one piece of sushi of each type. Note
that it means that there is at least one valid continuous segment.

OUTPUT
Print a single integer — the maximum length of a valid continuous segment.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> susi(n);
  for (auto &el : susi) std::cin >> el;

  int tunec = 0, ugor = 0, maximum = 0, last = susi[0];

  for (int t : susi) {
    if (last == t) {
      if (t == 1)
        tunec++;
      else
        ugor++;
    } else {
      maximum = std::max(maximum, std::min(tunec, ugor));
      if (t == 1)
        tunec = 1;
      else
        ugor = 1;
      last = t;
    }
  }

  maximum = 2 * std::max(maximum, std::min(tunec, ugor));

  std::cout << maximum << std::endl;

  return 0;
}
