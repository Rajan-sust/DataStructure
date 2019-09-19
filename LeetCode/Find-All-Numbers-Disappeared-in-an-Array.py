class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        for x in nums:
            idx = abs(x)-1
            nums[idx] = -abs(nums[idx])
        return [idx+1 for idx, x in enumerate(nums) if x > 0]
            