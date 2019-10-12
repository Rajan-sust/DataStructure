import random
random.seed()

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        while True:
            candidate = random.choice(nums)
            if sum(1 for elem in nums if elem == candidate) * 2 > n:
                return candidate
            #endif
        #endwhile
