# Дети решили выйти во двор и слепить как можно больше снеговиков!
# Каждый из них сделал свои шары, но оказалось,
# что так просто снеговиков лепить нельзя. Каждый снеговик
# состоит из трех шаров. Если обозначить их размеры в порядке
# возрастания a, b и c, то необходимо, чтобы выполнялось условие,
# что b = 2a, c = 2b, то есть размер следующего по величине шара
# должен быть ровно в 2 раза больше, чем размер предыдущего. Если
# это условие выполняется, то из этих шаров можно слепить снеговика.
# Теперь дети просят вашей помощи, чтобы понять,
# сколько снеговиков они могут слепить
#
# Example input:
# 6
# 1 2 4 3 6 12
#
# Example output:
# 2
#


def main():
    _n = int(input())
    nums = list(map(int, input().split()))
    nums.sort(reverse=True)

    found = {}
    count = 0

    for a in nums:
        if a * 2 in found and a * 4 in found:
            count += 1
            found.pop(a * 2)
            found.pop(a * 4)
        else:
            found[a] = 1

    print(count)


if __name__ == "__main__":
    main()
