def is_leap(y: int):
    return y % 4 != 0 or (y % 100 == 0 and y % 400 != 0)


def to_days(day: int, month: int, year: int):
    month_to_days: list[int | None] = [
        None,
        31,
        None,
        31,
        30,
        31,
        30,
        31,
        31,
        30,
        31,
        30,
    ]
    days = 0
    for y in range(1, year):
        days += 366 if is_leap(y) else 365

    for m in range(1, month):
        if m == 2:
            days += 29 if is_leap(year) else 28
        else:
            days += month_to_days[m] or 0

    return days + day


def add_years(day: int, month: int, year: int, offset: int):
    year += offset
    return day, month, year


OUT, IN = (1, 2)


def solution(events: list[tuple[int, int, int]]):
    if len(events) == 0:
        print(0)
        return

    events.sort()

    contemps: set[int] = set()
    updated = False

    for _, type_e, i_man in events:
        if type_e == IN:
            contemps.add(i_man)
            updated = True
        else:
            if updated:
                print(*contemps)
                updated = False
            contemps.remove(i_man)


def main():
    n = int(input())
    events: list[tuple[int, int, int]] = []

    for i_man in range(1, n + 1):
        s = input()
        d1, m1, y1, d2, m2, y2 = map(int, s.split())
        # tin = to_days(d1, m1, y1)
        tout = to_days(d2, m2, y2)

        t18 = to_days(d1, m1, y1 + 18)
        if t18 < tout:
            t80 = to_days(d1, m1, y1 + 80)
            events.append((t18, IN, i_man))
            events.append((min(tout, t80), OUT, i_man))

    solution(events)


if __name__ == "__main__":
    main()
