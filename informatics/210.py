def main():
    n = int(input())
    source = [int(i) for i in input().split()]
    source.sort()

    dp = [0] * n
    dp[1] = source[1] - source[0]

    if n > 2:
        dp[2] = source[2] - source[0]
        for i in range(3, n):
            dp[i] = min(dp[i - 2], dp[i - 1]) + source[i] - source[i - 1]

    print(dp[n - 1])


if __name__ == "__main__":
    main()
