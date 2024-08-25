# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        # Initialize sum to 0
        left_leaves_sum = 0

        # Check if the left child is a leaf
        if root.left and not root.left.left and not root.left.right:
            left_leaves_sum += root.left.val

        # Recursively call on left and right children
        left_leaves_sum += self.sumOfLeftLeaves(root.left)
        left_leaves_sum += self.sumOfLeftLeaves(root.right)

        return left_leaves_sum
        