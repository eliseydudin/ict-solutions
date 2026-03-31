def path(board_x: int, board_y: int, korm_x: int, korm_y: int):
    dx = [-2, -1, 1, 2, -2, -1, 1, 2]
    dy = [-1, -2, -2, -1, 1, 2, 2, 1]

    step_count = [[0] * board_y for _ in range(board_x)]
    hittable = [[False] * board_y for _ in range(board_x)]
    k = [[korm_x - 1, korm_y - 1]]
    hittable[korm_x - 1][korm_y - 1] = True
    while len(k) != 0:
        z = k.pop()

        for i in range(8):
            newx = z[0] + dx[i]
            newy = z[1] + dy[i]
            if on_board(newx, newy, board_x, board_y):
                if not hittable[newx][newy]:
                    hittable[newx][newy] = True
                    k.insert(0, [newx, newy])
                    step_count[newx][newy] = step_count[z[0]][z[1]] + 1

    step_count[korm_x - 1][korm_y - 1] = -1
    return step_count


def on_board(newx: int, newy: int, board_x: int, board_y: int):
    if 0 <= newx < board_x and 0 <= newy < board_y:
        return True
    else:
        return False


def main():
    board_x, board_y, korm_x, korm_y, bloha = map(int, input().split())
    if bloha == 0:
        return -1

    a = list((list(map(int, input().split())) for _ in range(bloha)))

    count = 0
    array = path(board_x, board_y, korm_x, korm_y)

    for i in range(bloha):
        if array[a[i][0] - 1][a[i][1] - 1] == -1:
            count += 0
        elif array[a[i][0] - 1][a[i][1] - 1] == 0:
            return -1
        else:
            count += array[a[i][0] - 1][a[i][1] - 1]

    return count


print(main())
