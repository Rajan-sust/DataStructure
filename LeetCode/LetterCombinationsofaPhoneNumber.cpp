#include <unordered_map>


class Solution {
public:
    unordered_map<char, string> mp;
    Solution() {
        mp = {
        {'2',"abc"},
        {'3',"def"},
        {'4', "ghi"}, 
        {'5', "jkl"}, 
        {'6', "mno"},
        {'7', "pqrs"}, 
        {'8', "tuv"}, 
        {'9', "wxyz"}};
    }

    void rec(int pos, int N, string cur, const string &digits, vector<string> &ans) {
        if(pos == N){
            ans.emplace_back(cur);
            return;
        }
        for(char ch: mp[digits[pos]]) {
            rec(pos+1, N, cur+ch, digits, ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) {
            return {};
        }
        vector<string> ans;
        int N = digits.size();
        rec(0, N, "", digits, ans);
        return ans;
    }
    
   
};



