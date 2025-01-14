#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int32_t> sieve_of_eratosthenes(const int32_t &limit) {
  std::vector<bool> is_prime(limit + 1, true);
  std::vector<int32_t> primes;
  is_prime[0] = is_prime[1] = false;

  for (int32_t p = 2; p * p <= limit; p++) {
    if (is_prime[p]) {
      for (int32_t i = p * p; i <= limit; i += p) {
        is_prime[i] = false;
      }
    }
  }

  for (int32_t p = 2; p <= limit; p++) {
    if (is_prime[p]) {
      primes.push_back(p);
    }
  }

  return primes;
}

inline bool is_prime(const int32_t &n, const std::vector<int32_t> &primes) {
  if (n < 2) {
    return false;
  } else if (n <= primes.back()) {
    return binary_search(primes.begin(), primes.end(), n);
  }

  for (const int32_t &prime : primes) {
    if (prime * prime > n) {
      break;
    }
    if (n % prime == 0) {
      return false;
    }
  }

  return true;
}

std::unordered_map<int32_t, int32_t> prime_cache;

int32_t closest_prime(const int32_t &n) {
  if (prime_cache.find(n) != prime_cache.end()) return prime_cache[n];

  static const int32_t LIMIT = 3163;  // sqrt(10^7) + 1
  static const std::vector<int32_t> small_cache = sieve_of_eratosthenes(LIMIT);

  int32_t i = n;

  while (true) {
    if (is_prime(i, small_cache)) {
      prime_cache[n] = i;
      return i;
    }
    i += 1;
  }
}

inline int32_t closest_power_of_2(int32_t n) {
  n -= 1;
  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  n += 1;
  return n;
}

int main() {
  int32_t n, a;
  std::cin >> n;

  for (int32_t i = 0; i < n; i++) {
    std::cin >> a;
    std::cout << (a < 2 ? 1 : std::min(closest_power_of_2(a), closest_prime(a)))
              << ' ';
  }
  std::cout << std::endl;

  return 0;
}
