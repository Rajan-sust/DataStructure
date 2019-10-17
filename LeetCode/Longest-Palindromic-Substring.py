class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()){
            return s;
        }
        int n = s.size(), mx = 0, start;
        int base = 131, mod = 1000000007;
        for(int i = 0; i < n; i++) {
            long long frwd = 0, rev = 0, p = 1;
            
            for(int j = i; j <n; j++) {
                frwd = (frwd + s[j]*p)%mod;
                p = (p*base)%mod;
                rev = (rev*base + s[j]) %mod;
                if(frwd == rev){
                    if(j-i+1 > mx) {
                        mx = j - i + 1;
                        
                        start = i;
                    }
                }
                
                
            }
        }
        return s.substr(start,mx);
        
        
    }
};
