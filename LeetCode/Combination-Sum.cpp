#include <vector>

class Solution {
public:
    
    void rec(int pos, int cur, int target, vector<int>temp, vector<int> &candidates, vector< vector<int> > &ans) {
       
        if(cur == target) {
            ans.push_back(temp);
            return;
        }
        if(cur > target) {
            return;
        }
        
        for(int i = pos; i < int(candidates.size()); i++) {
            int x = candidates[i];
            temp.push_back(x);
            rec(i, cur+x, target, temp, candidates, ans);
            temp.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector< vector<int> > ans;
        rec(0, 0, target, vector<int>() , candidates, ans);
        return ans;
    }
};