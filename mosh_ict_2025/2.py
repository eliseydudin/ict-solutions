# this code works :3
# 70/100 points


from functools import lru_cache


def closest_power_of_2(num: int) -> int:
    num -= 1
    num |= num >> 1
    num |= num >> 2
    num |= num >> 4
    num |= num >> 8
    num |= num >> 16
    num += 1
    return num


@lru_cache(None)
def is_prime(n: int) -> bool:
    if n <= 1:
        return False
    if n <= 3:
        return True

    if n % 2 == 0 or n % 3 == 0:
        return False

    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6

    return True


def closest_prime(num: int) -> int:
    while not is_prime(num):
        num += 1
    return num


def solve(num: int) -> int:
    if num == 0:
        return 1
    return min(closest_power_of_2(num), closest_prime(num))


def main():
    _n = int(input())
    nums = map(int, input().split())
    for inp in nums:
        print(solve(inp), end=" ")
    print()


if __name__ == "__main__":
    main()
