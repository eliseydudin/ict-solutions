def solve(x: int, y: int, n: int) -> int:
    if y == 8:
        return n
    if x == 1:
        return solve(2, y + 1, n)
    if x == 8:
        return solve(7, y + 1, n)
    return solve(x + 1, y + 1, n) + solve(x - 1, y + 1, n)


def main():
    x, y = map(int, input().split())
    print(solve(x, y, 1))


if __name__ == "__main__":
    main()
