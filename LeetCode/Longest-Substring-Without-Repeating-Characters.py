import numpy as np

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        lo , hi , n = 0 , -1, len(s)
        cnt = np.zeros((128,))
        mx = 0
        while hi < n-1:
            if cnt[ord(s[hi+1])] == 0:
                hi += 1
                cnt[ord(s[hi])] += 1
                
            else:
                cnt[ord(s[lo])] -= 1
                lo += 1
            mx = max(mx, hi - lo + 1)
        return mx
