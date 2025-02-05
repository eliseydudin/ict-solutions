# TODO


def main():
    n, k = map(int, input().split())
    halls: list[list[bool]] = []
    for _ in range(n):
        halls.append([False] * n)

    for _ in range(k):
        left, right = map(int, input().split())
        halls[left - 1][right - 1] = True
        halls[right - 1][left - 1] = True

    _m = int(input())
    robots = list(map(int, input().split()))


if __name__ == "__main__":
    main()
