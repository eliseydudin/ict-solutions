import math


def find_ys_of_circle(x: int, xc: int, yc: int, r: int):
    d = (2 * yc) ** 2 - 4 * (yc**2 - r**2 + (x - xc) ** 2)
    if d < 0:
        return None
    return [(2 * yc + math.sqrt(d)) / 2, (2 * yc - math.sqrt(d)) / 2]


def main():
    x1, y1, x2, y2 = map(int, input().split())

    x_left = min(x1, x2)
    x_right = max(x1, x2)
    y_down = min(y1, y2)
    y_up = max(y1, y2)

    xc, yc, r = map(int, input().split())

    count = 0

    for x in range(x_left, x_right + 1):
        ys = find_ys_of_circle(x, xc, yc, r)
        if ys is None:
            continue

        y1, y2 = ys
        y1 = min(y_up, math.floor(y1))
        y2 = max(y_down, math.ceil(y2))

        if y2 > y1:
            continue

        count += y1 - y2 + 1

    print(count)


if __name__ == "__main__":
    main()
