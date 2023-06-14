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
    int minDiff;
    TreeNode *prevNode;
    
    void explore(TreeNode* root){
        if(root == NULL){
            return ;
        }
        explore(root->left);
        if(prevNode != NULL){
            minDiff = min(minDiff, root->val - prevNode -> val);
        }
        prevNode = root;
        explore(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        minDiff = INT_MAX;
        prevNode = NULL;
        explore(root);
        return minDiff;
    }
};