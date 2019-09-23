class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector <int> cnt(32,0);
        for(int x: nums) {
            for(int j = 0; j<32; j++) {
                if(x & (1<<j)) {
                    cnt[j] += 1;
                }
            }
        }
        int ans = 0;
        for(int i=0 ; i < 32; i++) {
            ans += (cnt[i] % 3)*(1<<i);
        }
        return ans;
        
    }
};