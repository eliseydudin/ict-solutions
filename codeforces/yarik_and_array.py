"""
A subarray is a continuous part of array.
Yarik recently found an array 𝑎 of 𝑛 elements and became very interested in finding the
maximum sum of a non empty subarray. However, Yarik doesn't like consecutive integers
with the same parity, so the subarray he chooses must have alternating parities for
adjacent elements.

For example, [1,2,3] is acceptable, but [1,2,4] is not,
as 2 and 4 are both even and adjacent.

You need to help Yarik by finding the maximum sum of such a subarray.

INPUT
The first line contains an integer 𝑡 (1≤𝑡≤104) — number of test cases. Each test
case is described as follows.

The first line of each test case contains an integer 𝑛 (1≤𝑛≤2⋅105) — length of the array.

The second line of each test case contains 𝑛
integers 𝑎1,𝑎2,…,𝑎𝑛 (−103≤𝑎𝑖≤103) — elements of the array.

It is guaranteed that the sum of 𝑛 for all test cases does not exceed 2⋅105.

OUTPUT
For each test case, output a single integer — the answer to the problem.
"""


def solve(arr: list[int], N: int):
    cur_sum = arr[0]
    maximum_sum = arr[0]

    for i in range(1, N):
        if arr[i] % 2 != arr[i - 1] % 2:
            if cur_sum + arr[i] > arr[i]:
                cur_sum += arr[i]
            else:
                cur_sum = arr[i]
        else:
            cur_sum = arr[i]

        maximum_sum = max(maximum_sum, cur_sum)

    return maximum_sum


def main():
    n = int(input())
    answers = []

    for _ in range(n):
        N = int(input())
        A = list(map(int, input().split()))
        answers.append(solve(A, N))

    for ans in answers:
        print(ans)


if __name__ == "__main__":
    main()
