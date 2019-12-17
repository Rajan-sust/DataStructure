class Solution {
public:
    void rec(int pos, int N, string cur, int open, int close, vector<string> &ans) {
        if((open-close) < 0) {
            return;
        }
        if(pos == N) {
            if(open == close){
                ans.emplace_back(cur);
            }
            return;
        }
        rec(pos+1, N, cur+"(", open+1, close, ans);
        rec(pos+1, N, cur+")", open, close+1, ans);
    }
    vector<string> generateParenthesis(int n) {
        if(n == 0) {
            return {};
        }
        vector<string> ans;
        rec(0,2*n,"",0,0,ans);
        return ans;
        
    }
    
};

