def solve(n: int):
    cache = [0] * (n + 1)

    for i in range(2, n + 1):
        v = cache[i - 1]
        if i % 2 == 0:
            v = min(v, cache[i // 2])
        if i % 3 == 0:
            v = min(v, cache[i // 3])
        cache[i] = v + 1

    return cache[-1]


def main():
    n = int(input())
    print(solve(n))


if __name__ == "__main__":
    main()
