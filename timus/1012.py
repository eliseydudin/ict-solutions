def main():
    n = int(input())
    k = int(input())

    nums = (n + 1) * [0]
    nums[0] = 1
    nums[1] = k - 1
    for i in range(2, n + 1):
        nums[i] = (k - 1) * (nums[i - 1] + nums[i - 2])
    print(nums[n])


if __name__ == "__main__":
    main()
