def f(num: int, target: int, deny: int):
    if num < target or num == deny:
        return 0
    if num == target:
        return 1
    return (
        f(num - 2, target, deny) + f(num // 2, target, deny) + f(num // 3, target, deny)
    )


print(f(40, 2, 22))
