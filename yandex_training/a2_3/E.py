# NO WORKY :(

# Натуральное число N является числом Фибоначчи тогда и только
# тогда, когда 5N^2+4 или 5N^2−4 является квадратом.
# https://ru.wikipedia.org/wiki/Числа_Фибоначчи


def is_fib(n: int) -> bool:
    return (5 * (n**2) - 4) ** 0.5 % 1 == 0 or (5 * (n**2) + 4) ** 0.5 % 1 == 0


def main():
    n = int(input())
    for _ in range(n):
        num = int(input())
        if is_fib(num):
            print("Yes")
        else:
            print("No")


if __name__ == "__main__":
    main()
