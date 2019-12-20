/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        queue< pair<TreeNode*,int> > Q;
        Q.push({root, 0});
        vector< pair<int,int> > v;
        
        while(not Q.empty()) {
            auto elem = Q.front();
            Q.pop();
            TreeNode *u = elem.first;
            if(u == NULL) {
                continue;
            }
            int level = elem.second;
            v.push_back({u->val, level});
            Q.push({u->left, level+1});
            Q.push({u->right, level+1});
        }
        
        int n = v.back().second + 1;
        vector < vector<int> > ans(n);
        for(auto i: v) {
            ans[i.second].push_back(i.first);
        }
        for(int i = 0; i < n; i++){
            if(i&1){
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
        
    }
};
