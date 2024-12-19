def main():
    n, m = map(int, input().split())

    dp: list[list[int]] = []

    for _ in range(n + 1):
        to_append = [0] * (m + 1)
        dp.append(to_append)

    dp[1][1] = 1

    for i in range(2, n + 1):
        for j in range(2, m + 1):
            dp[i][j] = dp[i - 1][j - 2] + dp[i - 2][j - 1]

    print(dp[n][m])


if __name__ == "__main__":
    main()
