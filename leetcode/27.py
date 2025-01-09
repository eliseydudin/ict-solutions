class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        dup = 0
        for i in range(len(nums)):
            i -= dup
            if nums[i] == val:
                dup += 1
                nums.pop(i)

        return len(nums)
