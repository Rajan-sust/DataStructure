
#include <bitset>

class Solution {
private:
    map<int, bool > mp;
    map<int, int> conv;
public:
    
    bool is_ok(vector<int> &temp) {
        int h = 0;
        for(int num: temp) {
            int number = conv[num];
            while(number) {
                int rem = number % 10;
                rem += 1;
                h = (h*57 + rem)%100011;
                number/=10;
            }
        }
        //cout<<h<<endl;
        if(mp.count(h)) {
            return false;
        } else{
            mp[h] = true;
            return true;
        }
    }
    void rec(bitset<32> visit, vector<int> temp, vector<int> &num, vector< vector<int> > &ans) {
        if(temp.size() == num.size()) {
            if(is_ok(temp)) {
                ans.emplace_back(temp);
            }
            
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
    vector<vector<int>>  permuteUnique(vector<int>& nums) {
        int cnt = 0;
        for(int num: nums) {
            if(not conv.count(num)) {
                cnt += 1;
                conv[num] = cnt;
            }
        }
        vector< vector<int> > ans;
        bitset<32> visit;
        rec(visit, vector<int>(), nums, ans);
        return ans;
        
        
    }
};


/*
1. Number can be zero and negative. If zero occurs, hash function code doesn't enter in while loop.
2. Overflow by means of mod.
2. Overflow handle in hash
*/

