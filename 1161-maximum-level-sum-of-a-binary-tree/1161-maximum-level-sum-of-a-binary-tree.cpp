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
    map<int,int> LS;
    
    void sumByLevel(TreeNode *root, int lvl){
        if(root == NULL){
            return ;
        }
        LS[lvl] += root -> val;
        sumByLevel(root->left, lvl+1);
        sumByLevel(root->right, lvl+1);
    }
    
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN, maxLevel = 1;
        
        sumByLevel(root, 1);
        
        for(auto [lvl, sum]: LS){
            if(maxSum < sum){
                maxSum = sum;
                maxLevel = lvl;
            }
        }
        return maxLevel;
    }
};