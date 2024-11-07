def main():
    n = int(input())
    a, b, c = 3, 8, 22

    for _ in range(n - 1):
        c = b * 2 + a * 2
        a = b
        b = c

    print(a)


if __name__ == "__main__":
    main()
