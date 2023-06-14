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
    vector<int> list;
    
    void explore(TreeNode* root){
        if(root == NULL){
            return ;
        }
        explore(root->left);
        list.push_back(root->val);
        explore(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        minDiff = INT_MAX;
        explore(root);
        for(int i = 1; i < list.size(); ++i){
            minDiff = min(minDiff, list[i] - list[i-1]);
        }
        return minDiff;
    }
};