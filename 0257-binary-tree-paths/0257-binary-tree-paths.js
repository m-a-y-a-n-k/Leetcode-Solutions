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
 * @return {string[]}
 */
var binaryTreePaths = function(root) {
    if(!root){
        return [];
    }
    if(!root.left && !root.right){
        return [`${root.val}`];
    }
    const leftPaths = binaryTreePaths(root.left);
    const rightPaths = binaryTreePaths(root.right);
    return leftPaths.map(path => `${root.val}->${path}`).concat(rightPaths.map(path => `${root.val}->${path}`));
};