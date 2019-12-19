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
    bool rec(TreeNode *node1, TreeNode *node2) {
        if(node1 == NULL and node2 == NULL) {
            return true;
        }
        if(node1 == NULL or node2 == NULL) {
            return false;
        }
        if(node1->val == node2->val) {
            return rec(node1->left, node2->right) and rec(node1->right, node2->left);
        } else{
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        return rec(root, root);
        
    }
};
