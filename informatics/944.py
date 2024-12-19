def main():
    n, m = map(int, input().split())
    result = [[int(it) for it in input().split()] for _ in range(n)]

    for cln in range(m - 2, -1, -1):
        result[-1][cln] += result[-1][cln + 1]

    for row in range(n - 2, -1, -1):
        result[row][-1] += result[row + 1][-1]

    for row in range(n - 2, -1, -1):
        for cln in range(m - 2, -1, -1):
            result[row][cln] += min(result[row + 1][cln], result[row][cln + 1])

    print(result[0][0])


if __name__ == "__main__":
    main()
