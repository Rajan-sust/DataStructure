class Solution:
    def isPalindrome(self, x: int) -> bool:
        s = str(x)
        for idx, ch in enumerate(s):
            if ch != s[(-1)*(idx+1)]:
                return False
            #endif
        #endfor
        return True
