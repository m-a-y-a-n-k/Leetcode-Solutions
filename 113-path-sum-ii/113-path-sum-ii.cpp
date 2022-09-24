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
    vector<vector<int>> result;
    vector<int> path;
    
    void utilPathSum(TreeNode* root, int currSum, int targetSum){
        if(!root){
            return ;
        }
        path.push_back(root->val);
        currSum += root -> val;
        
        if(!root->left && !root->right){
            
            if(currSum == targetSum){
                result.push_back(path);
            }
        }
        
        utilPathSum(root->left, currSum, targetSum);
        utilPathSum(root->right, currSum, targetSum);
        
        path.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        utilPathSum(root, 0, targetSum);
        
        return result;
    }
};