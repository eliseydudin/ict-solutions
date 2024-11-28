def f(num: int, target: int):
    if num > target:
        return 0
    if num == target:
        return 1
    return f(num + 2, target) + f(num**2, target) + f(num**3, target)


print(f(10, 1000))
