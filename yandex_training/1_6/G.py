n = int(input())
m = int(input())
t = int(input())


def check(width: int):
    square = n * m

    n_new = n - (width * 2)
    m_new = m - (width * 2)

    if n_new > 0 and m_new > 0:
        empty_space = n_new * m_new
        return empty_space < square and t >= (square - empty_space)
    return False


def binary_search(left: int, right: int):
    while left < right:
        mid = (left + right + 1) // 2

        if check(mid):
            left = mid
        else:
            right = mid - 1

    return left


print(binary_search(0, 10**30))
