/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getHeight(TreeNode* root){
        if(root == nullptr){
            return 0;
        }    
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        if(l == -1 || r == -1 || abs(l - r) > 1)
            return -1;
        int h = 1 + max(l,r);
        return h;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        return getHeight(root) != -1;
    }
};