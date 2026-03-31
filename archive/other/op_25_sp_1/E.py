#
# Task 14 Stalker
# 100/100 points
#


from collections import deque


def readline() -> str:
    line = input().strip()
    if line:
        return line
    else:
        return readline()


def readmap() -> deque[set[int]]:
    g: dict[int, set[int]] = dict()
    for _ in range(int(readline())):
        a, b = map(int, readline().split())
        if a not in g:
            g[a] = set()
        if b not in g:
            g[b] = set()
        g[a].add(b)
        g[b].add(a)

    segments: deque[set[int]] = deque()
    while g:
        a, queue = g.popitem()
        segment = {a}
        segments.append(segment)
        while queue:
            a = queue.pop()
            if a not in segment:
                segment.add(a)
                queue.update(g[a])
                g.pop(a)

    return segments


def main():
    n, k = map(int, readline().split())
    outs: list[set[int]] = [set() for _ in range(n + 1)]

    for _ in range(k):
        for segment in readmap():
            outs.append(segment)
            index = len(outs) - 1
            for v in segment:
                outs[v].add(index)

    queue = deque([1])
    visited: set[int] = set()
    distance = [-1] * len(outs)
    distance[1] = 0

    while queue:
        v = queue.pop()
        if v in visited:
            continue

        visited.add(v)
        push = queue.append if v > n else queue.appendleft
        new_cost = distance[v] + (v <= n)

        for w in outs[v]:
            cost = distance[w]
            if cost == -1 or cost > new_cost:
                distance[w] = new_cost
                push(w)

    print(distance[n])


if __name__ == "__main__":
    main()
