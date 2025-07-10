# NO WORKY
def main():
    n = int(input())
    k = int(input())
    m = int(input())

    num1 = 1
    num2 = k - 1
    for _ in range(2, n + 1):
        new_num = ((k - 1) * (num2 + num1)) % m
        num1 = num2
        num2 = new_num

    print(num2)


if __name__ == "__main__":
    main()
