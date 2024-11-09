n = int(input())
e = []

for _ in range(n):
    h1, m1, h2, m2 = map(int, input().split())
    topen = h1 * 60 + m1
    tclose = h2 * 60 + m2
    if topen >= tclose:
        e.append((0, 1))
        e.append((1440, 2))

    e.append((topen, 1))
    e.append((tclose, 2))

len_events = len(e)
e.sort()
kassa = 0
minutes = 0

for i in range(len_events):
    if kassa == n:
        minutes += e[i][0] - e[i - 1][0]
    type_e = e[i][1]
    if type_e == 1:
        kassa += 1
    else:
        kassa -= 1

print(minutes)
