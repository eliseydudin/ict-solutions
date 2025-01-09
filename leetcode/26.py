class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        last_num = nums[0]
        k = 1
        dup = 0

        for i in range(1, len(nums)):
            i -= dup
            if nums[i] != last_num:
                k += 1
                last_num = nums[i]
            else:
                dup += 1
                nums.pop(i)

        return k
