def main():
    student_num, interval = map(int, input().split())

    student_coord = [[0, 0] for _ in range(student_num * 2)]
    str_input = input().split()

    for i in range(student_num):
        student_coord[i][0] = int(str_input[i])
        student_coord[i][1] = i
        student_coord[i + student_num][0] = student_coord[i][0] + interval
        student_coord[i + student_num][1] = student_num + i

    student_coord.sort(key=lambda x: (x[0], x[1]))

    var_cnt = 1
    max_var = 1
    variants = [0] * student_num

    for i in range(student_num * 2):
        if student_coord[i][1] < student_num:
            var_cnt += 1
        if max_var < var_cnt:
            max_var = var_cnt
        if student_coord[i][1] >= student_num:
            var_cnt -= 1

    k = 1
    for i in range(student_num * 2):
        if student_coord[i][1] < student_num:
            variants[student_coord[i][1]] = k
            k += 1
            if k > max_var - 1:
                k = 1

    print(max_var - 1)
    print(*variants)


if __name__ == "__main__":
    main()
