def f(n: int):
    if n == 1:
        return 0
    v = f(n - 1)
    if n % 2 == 0:
        v = min(v, f(n // 2))
    if n % 3 == 0:
        v = min(v, f(n // 3))
    return v + 1


print(f(int(input())))
