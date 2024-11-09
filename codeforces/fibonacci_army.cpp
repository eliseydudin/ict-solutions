/*
King Cambyses loves Fibonacci numbers. He has several armies. Today he wants to
make a new army for himself and he wants the number of men in this army to be
the n-th Fibonacci number.

Given n you should find n-th Fibonacci number. The set of Fibonacci numbers
start with f0 = f1 = 1 and for each i ≥ 2, fi = fi - 1 + fi - 2.

INPUT
Input contains a single integer n (1 ≤ n ≤ 20).

OUTPUT
Write a single integer. The n-th Fibonacci number.
*/

#include <cstdint>
#include <iostream>
#include <map>

typedef uint64_t u64;

u64 fib(u64 n, std::map<u64, u64> &cache) {
  if (cache.find(n) != cache.end()) {
    return cache[n];
  }

  u64 res = fib(n - 1, cache) + fib(n - 2, cache);
  cache[n] = res;
  return res;
}

int main() {
  std::map<u64, u64> cache;
  cache[0] = 1;
  cache[1] = 1;

  u64 inp;
  std::cin >> inp;
  std::cout << fib(inp, cache) << std::endl;

  return 0;
}
