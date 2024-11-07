def solve(graph: list[list[int]], n: int):
    color = [-1] * n
    for i in range(n):
        if color[i] == -1:
            stack = [i]
            color[i] = 0
            while stack:
                v = stack.pop()
                for u in graph[v]:
                    if color[u] == -1:
                        stack.append(u)
                        color[u] = 1 - color[v]
                    elif color[u] == color[v]:
                        return False, []

    table1 = [i + 1 for i in range(n) if color[i] == 0]
    return True, table1


def main():
    n, m = map(int, input().split())

    graph = [[] for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        graph[u - 1].append(v - 1)
        graph[v - 1].append(u - 1)

    possible, table1 = solve(graph, n)
    if possible:
        print("YES")
        print(*table1)
    else:
        print("NO")


if __name__ == "__main__":
    main()
