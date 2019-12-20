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
private:
    int mx_level;
    
public:
    Solution() {
        mx_level = 0;
    }
    void dfs(TreeNode* node, int level) {
        if(node == nullptr) {
            return;
        }
        mx_level = max(mx_level, level);
        dfs(node->left, level+1);
        dfs(node->right, level+1);
    }
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        dfs(root,1);
        return mx_level;
        
    }
};
