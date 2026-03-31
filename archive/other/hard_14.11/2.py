import math


def f(num: int, target: int, deny: int):
    if num < target or num == deny:
        return 0
    if num == target:
        return 1
    return (
        f(num - 1, target, deny)
        + f(num - 2, target, deny)
        + f(math.floor(num / 3), target, deny)
    )


print(f(30, 8, 11))
