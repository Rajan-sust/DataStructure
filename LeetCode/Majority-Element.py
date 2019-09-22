from collections import defaultdict

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        mp = defaultdict(int)
        for num in nums:
            mp[num] += 1
        #endfor
        n = len(nums)
        for key, val in mp.items():
            if 2*val > n:
                return key
            #endif
        #endfor