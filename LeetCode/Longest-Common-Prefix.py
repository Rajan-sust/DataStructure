from collections import defaultdict

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        mp = defaultdict(int)
        for s in strs:
            prefix = ''
            for letter in s:
                prefix += letter
                mp[prefix] += 1
            #endfor
        #endfor
        total_words = len(strs)
        candidate = [key for key,val in mp.items() if val == total_words]
        if len(candidate) == 0:
            return ''
        #endif
        return max(candidate, key = lambda x: len(x))