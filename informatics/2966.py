global n, m, matrix, pathmatrix


def solve(x: int, y: int) -> tuple[int, list[str]]:
    try:
        return pathmatrix[x, y]
    except KeyError:
        if x > 0:
            left = solve(x - 1, y)
        else:
            left: tuple[int, list[str]] = (-1, [])
        if y > 0:
            up = solve(x, y - 1)
        else:
            up: tuple[int, list[str]] = (-1, [])
        maxdist = max(left[0], up[0]) + matrix[x][y]
        if left[0] > up[0]:
            path = pathmatrix[x - 1, y][1].copy()
            path.append("D")
        else:
            path = pathmatrix[x, y - 1][1].copy()
            path.append("R")
        pathmatrix[x, y] = (maxdist, path)
        return pathmatrix[x, y]


n, m = [int(i) for i in input().split()]
matrix = [[int(i) for i in input().split()] for _ in range(n)]

pathmatrix: dict[tuple[int, int], tuple[int, list[str]]] = {(0, 0): (matrix[0][0], [])}

res = solve(n - 1, m - 1)
print(res[0])
print(" ".join(res[1]))
