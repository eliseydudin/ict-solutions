def solve(k: int, p: int) -> int:
    if k < 2:
        return 0

    num = (k + 1) * [0]
    num[2] = 1

    for i in range(2, k):
        if (i + 1) % 2 == 1:
            num[i + 1] = num[i]
        else:
            num[i + 1] = num[i] + num[(i + 1) // 2]

    return num[k] % p


def main():
    k, p = map(int, input().split())
    print(solve(k, p))


if __name__ == "__main__":
    main()
