class Solution {
public:
    void push_n_times(vector<int> &v, int n, int x) {
        for(int i = 0; i < n; i++) {
            v.push_back(x);
        }
    }
    
    void pop_n_times(vector<int> &v, int n) {
        for(int i=0; i < n; i++) {
            v.pop_back();
        }
    }
    
    void rec(int pos, int cur, int N, int target, vector< pair<int,int> > &fre, vector<int> temp, vector< vector<int> > &ans) {
        if(cur == target) {
            ans.emplace_back(temp);
            return;
        }
        if(cur > target) {
            return;
        }
        if(pos == N) {
            return;
        }
        
        int val = fre[pos].first, n = fre[pos].second;
        for(int i = 0; i<=n; i++) {
            push_n_times(temp,i,val);
            rec(pos+1, cur + val*i , N, target, fre, temp, ans);
            pop_n_times(temp,i);
        }
    }
    vector< vector<int> > combinationSum2(vector<int>& candidates, int target) {
        map<int, int> mp;
        for(int x: candidates) {
            mp[x] += 1;
        }
        vector< pair<int,int> > fre(mp.begin(), mp.end());
        vector< vector<int> > ans;
        rec(0, 0, int(fre.size()), target, fre, vector<int>(), ans);
        return ans;
    }
};

