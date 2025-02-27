from collections import Counter


def solve(s: str):
    counter = Counter(s)

    odd = None
    for k, v in counter.items():
        if v % 2 == 1 and odd is None:
            odd = (k, v)
        elif v % 2 == 1 and odd is not None and ord(odd[0]) > ord(k):
            odd = (k, v)
        elif v % 2 == 1:
            counter[k] -= 1

    if odd is not None:
        del counter[odd[0]]

        if odd[1] > 1:
            count = odd[1]
            counter[odd[0]] = count - 1
            odd = (odd[0], 1)

    counter = dict(sorted(counter.items()))

    result = "".join(k * (v // 2) for k, v in counter.items())
    if odd is not None:
        result += odd[0] * ((odd[1] + 1) // 2)

    result += "".join(reversed(result[: len(result) - (1, 0)[odd is None]]))

    return result


def main():
    _n = int(input())
    string = input()

    print(solve(string))


if __name__ == "__main__":
    main()
