# NO WORKY :(

from math import sqrt


def mo_algorithm(
    n: int, m: int, q: int, k: int, beers: list[int], queries: list[tuple[int, ...]]
):
    block_size = int(sqrt(n))

    queries.sort(key=lambda x: (x[0] // block_size, x[1]))

    current_l = 0
    current_r = -1
    freq = [0] * (m + 1)
    count_k = 0
    results = [0] * q

    def add(beer: int):
        nonlocal count_k
        freq[beer] += 1
        if freq[beer] == k:
            count_k += 1
        elif freq[beer] == k + 1:
            count_k -= 1

    def remove(beer: int):
        nonlocal count_k
        if freq[beer] == k:
            count_k -= 1
        elif freq[beer] == k - 1:
            count_k += 1
        freq[beer] -= 1

    for idx, (l, r) in enumerate(queries):
        while current_r < r:
            current_r += 1
            add(beers[current_r])
        while current_r > r:
            remove(beers[current_r])
            current_r -= 1
        while current_l < l:
            remove(beers[current_l])
            current_l += 1
        while current_l > l:
            current_l -= 1
            add(beers[current_l])

        results[idx] = count_k

    return results


def main():
    n, m, q, k = map(int, input().split())
    beers = list(map(int, input().split()))
    queries = [tuple(map(int, input().split())) for _ in range(q)]

    results = mo_algorithm(n, m, q, k, beers, queries)
    for result in results:
        print(result)


if __name__ == "__main__":
    main()
