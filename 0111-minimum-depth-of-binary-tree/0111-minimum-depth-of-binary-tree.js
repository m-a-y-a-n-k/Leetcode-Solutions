/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var minDepth = function(root) {
    if(!root){
        return 0;
    }
    const minLeftDepth = minDepth(root.left);
    const minRightDepth = minDepth(root.right);
    if(!minLeftDepth){
        return minRightDepth + 1;
    }
    if(!minRightDepth){
        return minLeftDepth + 1;
    }
    return Math.min(minLeftDepth, minRightDepth) + 1;
};