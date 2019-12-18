#include <bitset>

class Solution {
public:
    void rec(bitset<32> visit, vector<int> temp, vector<int> &num, vector< vector<int> > &ans) {
        if(temp.size() == num.size()) {
            ans.emplace_back(temp);
            return;
        }
        int N = num.size();
        for(int i = 0; i < N; i++) {
            if(not visit.test(i)) {
                visit.set(i);
                temp.emplace_back(num[i]);
                rec(visit, temp, num, ans);
                visit.reset(i);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector< vector<int> > ans;
        bitset<32> visit;
        rec(visit, vector<int>(), nums, ans);
        return ans;
        
        
    }
};

