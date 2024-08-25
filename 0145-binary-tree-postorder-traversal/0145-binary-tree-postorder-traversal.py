# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def traverse(node):
            if not node:
                return []
            # Traverse the left subtree, then the right subtree, and finally the root node
            return traverse(node.left) + traverse(node.right) + [node.val]

        return traverse(root)