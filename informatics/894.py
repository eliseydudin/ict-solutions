import math


def main():
    velocity_max, eat_time = map(int, input().split())
    n = int(input())

    distances: list[int] = []
    times: list[float] = []
    all_time = 0

    for i in range(n):
        distance, time = input().split()
        distance = int(distance)
        h, m = map(int, time.split(":"))

        distances.append(distance - all_time)
        times.append(float(h * 60 + m))
        all_time = distance

    left = 0
    right = max(times)

    for i in range(100):
        mid = (left + right) / 2
        time = mid

        for i in range(len(distances) - 1):
            time += distances[i] / velocity_max
            if time >= times[i]:
                time += eat_time

        time += distances[-1] / velocity_max

        if time == times[-1]:
            break
        elif time > times[-1]:
            right = mid
        else:
            left = mid

    time = 2 * all_time / velocity_max + n * eat_time + right
    time = math.ceil(time)
    h = time // 60
    m = time % 60

    print(str(h).zfill(2) + ":" + str(m).zfill(2))


if __name__ == "__main__":
    main()
