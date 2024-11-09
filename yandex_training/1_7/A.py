n, m = map(int, input().split())
array = []

for i in range(m):
    x, y = map(int, input().split())
    array.append((x, 1))
    array.append((y, 2))

array.sort()

s = array[0][0] + n - 1 - array[len(array) - 1][0]

k = 0
for j in range(len(array) - 1):
    if array[j][1] == 1:
        k += 1
    elif array[j][1] == 2:
        k -= 1
    if k == 0 and array[j + 1][0] - array[j][0] > 0:
        s = array[j + 1][0] - array[j][0] - 1 + s

print(s)
