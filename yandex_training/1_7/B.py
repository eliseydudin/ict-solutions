n, m = map(int, input().split())
a = []

for i in range(n):
    x, y = map(int, input().split())
    x, y = min(x, y), max(x, y)
    a.append([x, "("])
    a.append([y, ")"])

m = list(map(int, input().split()))

for i in range(len(m)):
    a.append([m[i], "(("])

k = 0
a.sort()
d = {}

for i in range(len(a)):
    if a[i][1] == "(":
        k += 1
    elif a[i][1] == ")":
        k -= 1
    else:
        d[a[i][0]] = k

for i in m:
    print(d[i], end=" ")
print()
