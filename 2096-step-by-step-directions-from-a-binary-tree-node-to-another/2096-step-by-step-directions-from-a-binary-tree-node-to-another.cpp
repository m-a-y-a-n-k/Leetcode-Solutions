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
    string left, right;
    
    void getPathUtil(TreeNode *root, string &pre, int start, int end){
        if(!root){
            return ;
        }
        if(root->val == start){
            left = pre;
        }
        if(root -> val == end){
            right = pre;
        }
        pre.push_back('L');
        getPathUtil(root->left, pre, start, end);
        pre.pop_back();
        pre.push_back('R');
        getPathUtil(root->right, pre, start, end);
        pre.pop_back();
    }
    
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string r = "$", ans = "";
        getPathUtil(root, r, startValue, destValue);
        
        int i, ls = left.size(), rs = right.size();
        for(i = 0; i < ls; i++){
            if(left[i] != right[i]){
                break;
            }
        }
        
        int x = i; 
        for(; x < ls; x++){
            ans.push_back('U');
        }
        x = i;
        for(; x < rs; x++){
            ans.push_back(right[x]);
        }
        return ans;
    }
};