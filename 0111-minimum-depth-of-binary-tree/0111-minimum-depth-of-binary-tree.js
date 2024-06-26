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
    if(!minLeftDepth){
        return minDepth(root.right) + 1;
    }
    const minRightDepth = minDepth(root.right);
    if(!minRightDepth){
        return minLeftDepth + 1;
    }
    return Math.min(minLeftDepth, minRightDepth) + 1;
};