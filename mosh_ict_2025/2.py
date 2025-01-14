from bisect import bisect_right
import math


def sieve_of_eratosthenes(limit: int):
    is_prime = [True] * (limit + 1)
    primes = []
    is_prime[0] = is_prime[1] = False

    for p in range(2, int(limit**0.5) + 1):
        if is_prime[p]:
            for i in range(p * p, limit + 1, p):
                is_prime[i] = False

    for p in range(2, limit + 1):
        if is_prime[p]:
            primes.append(p)

    return primes


def is_prime(n: int, primes):
    if n < 2:
        return False
    if n <= primes[-1]:
        index = bisect_right(primes, n) - 1
        return primes[index] == n
    for prime in primes:
        if prime * prime > n:
            break
        if n % prime == 0:
            return False
    return True


prime_cache: dict = {}


def closest_prime(n: int):
    if n in prime_cache:
        return prime_cache[n]

    small_cache = sieve_of_eratosthenes(int(math.sqrt(10**7)) + 1)

    i = n
    while True:
        if is_prime(i, small_cache):
            prime_cache[n] = i
            return i
        i += 1


def closest_power_of_two(n: int):
    n -= 1
    n |= n >> 1
    n |= n >> 2
    n |= n >> 4
    n |= n >> 8
    n |= n >> 16
    return n + 1


def main():
    _n = int(input())
    inputs = map(int, input().split())

    for i in inputs:
        if i < 2:
            print(1, end=" ")
        else:
            print(min(closest_power_of_two(i), closest_prime(i)), end=" ")

    print()


if __name__ == "__main__":
    main()
