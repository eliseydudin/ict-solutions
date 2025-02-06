def main():
    maxn = 26
    a = [0] * (maxn + 1)
    n = int(input())

    a[1] = 1

    for i in range(1, maxn):
        a[i + 1] = 1 + 2 * a[i]

    for k in range(26, 0, -1):
        if n == 1:
            print(chr(ord("a") + k - 1))
            break
        elif n > a[k - 1] + 1:
            n = n - 1 - a[k - 1]
        else:
            n = n - 1


if __name__ == "__main__":
    main()

# 1
# a
# 2
# baa
# 3
# cbaabaa
