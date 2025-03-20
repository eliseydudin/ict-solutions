def main():
    a_string = input()
    b_string = input()

    a_container = [0] * 10
    b_container = [0] * 10

    for s in a_string:
        a_container[int(s)] += 1
    for s in b_string:
        b_container[int(s)] += 1

    b = True
    ok = False
    for i in range(9, -1, -1):
        if a_container[i] > 0 and b_container[i] > 0:
            ok = True
            if i == 0:
                b = False
            break

    if not ok:
        print(-1)
        return

    if not b:
        print(0)
        return

    for i in range(9, 0, -1):
        print(*(min(a_container[i], b_container[i]) * [i]), sep="", end="")
    if b:
        print(*(min(a_container[0], b_container[0]) * [0]), sep="", end="\n")
    else:
        print(0)


if __name__ == "__main__":
    main()
