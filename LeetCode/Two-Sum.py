class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}
        for idx, num in enumerate(nums):
            n = target - num
            if n not in mp:
                mp[num] = idx
            else:
                return [mp[n], idx]
