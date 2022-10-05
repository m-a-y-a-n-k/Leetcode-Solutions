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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1 || !root){
            return new TreeNode(val, root, nullptr);
        }
        queue<TreeNode*> Q;
        Q.push(root);
        
        while(!Q.empty() && depth != 1){
            int s = Q.size();
            --depth;
            
            for(int k = 0; k < s; ++k){
                TreeNode *curr = Q.front();
                Q.pop();
                
                if(depth == 1){
                    
                    TreeNode *left = new TreeNode(val, curr -> left, nullptr);
                    TreeNode *right = new TreeNode(val, nullptr, curr -> right);
                    
                    curr -> left = left;
                    curr -> right = right;
                    
                } else {
                    if(curr -> left){
                        Q.push(curr -> left);
                    }
                    
                    if(curr -> right){
                        Q.push(curr -> right);
                    }
                }
            }
        }
        
        return root;
    }
};