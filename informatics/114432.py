# NO WORKY
# this code only gets 45 points


def main():
    n = int(input())
    k = int(input())

    if k <= n:
        print(1, k)
        return

    pair = list(divmod(k, 2 * n + 1))
    pair[0] *= 2
    pair[0] += 1

    print(pair[0], pair[1])


if __name__ == "__main__":
    main()
