def main():
    n = int(input())
    cnt_ones = [0] * (n + 1)
    cnt_zeros = [0] * (n + 1)
    cnt_ones[0] = cnt_zeros[0] = 1
    n -= 1

    for i in range(1, n + 1):
        cnt_zeros[i] = cnt_zeros[i - 1] + cnt_ones[i - 1]
        cnt_ones[i] = cnt_zeros[i - 1]

    print(cnt_ones[n] + cnt_zeros[n])


if __name__ == "__main__":
    main()
