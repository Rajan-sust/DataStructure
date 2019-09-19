class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        /*
        Learn:
        Always mark a array with a number that does not appear in input
        */
        
     
        
        int len = nums.size();
        vector<int> ans(len, -1);
        
        for(int num: nums) {
            ans[num-1] = -2;
        }
        
        int lo = 0;
        
        for(int i = 0; i < len; i++) {
            if(ans[i] == -1) {
                ans[i] = -2;
                ans[lo] = i;
                lo += 1;
            }
        }
        
        while(! ans.empty()) {
            if(ans.back() == -2) {
                ans.pop_back();
            } else{
                break;
            }
        }
        
        for_each(ans.begin(), ans.end(), [](int &num){
            num += 1;
        });
        
        return ans;
        
        
        
    }
};