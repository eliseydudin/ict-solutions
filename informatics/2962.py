def solve(i: int, j: int, dp: list[list[int]], n: int, m: int) -> int:
    if i >= 0 and j >= 0 and i < n and j < m:
        if dp[i][j] == -1:
            dp[i][j] = (
                solve(i - 2, j - 1, dp, n, m)
                + solve(i - 2, j + 1, dp, n, m)
                + solve(i - 1, j - 2, dp, n, m)
                + solve(i + 1, j - 2, dp, n, m)
            )
    else:
        return 0

    return dp[i][j]


def main():
    n, m = map(int, input().split())
    dp: list[list[int]] = []

    for _ in range(n):
        dp.append(list([-1 for _ in range(m)]))

    dp[0][0] = 1

    print(solve(n - 1, m - 1, dp, n, m))


if __name__ == "__main__":
    main()
