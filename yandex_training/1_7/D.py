n = int(input())
events: list[tuple[int, int, int]] = []

for i in range(n):
    nowin, nowout = map(int, input().split())
    if nowout - nowin < 5:
        continue

    events.append((nowin, -1, i))
    events.append((nowout - 5, 1, i))

events.sort()

if len(events) == 0:
    print("0 10 20")
elif len(events) == 2:
    print(1, events[0][0], events[0][0] + 10)
else:
    best = 0
    first_best, second_best = 0, 0
    first_ad: set[int] = set()

    for i in range(len(events)):
        event1 = events[i]
        if event1[1] == -1:
            first_ad.add(event1[2])
            if len(first_ad) > best:
                best = len(first_ad)
                first_best = event1[0]
                second_best = event1[0] + 5

        second_ad_cnt = 0

        for j in range(i + 1, len(events)):
            event2 = events[j]
            if event2[1] == -1 and event2[2] not in first_ad:
                second_ad_cnt += 1
            if event2[0] - 5 >= event1[0] and len(first_ad) + second_ad_cnt > best:
                best = len(first_ad) + second_ad_cnt
                first_best = event1[0]
                second_best = event2[0]
            if event2[1] == 1 and event2[2] not in first_ad:
                second_ad_cnt -= 1

        if event1[1] == 1:
            first_ad.remove(event1[2])

    print(best, first_best, second_best)
