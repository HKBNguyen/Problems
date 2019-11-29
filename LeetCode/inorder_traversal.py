#!/usr/bin/python


class Solution:
    def tree_helper(self, res: List[int], root):
        if not root:
            return
        if root->left:
            self.tree_helper(res, root->left)
        res.append(root->val)
        if root->right:
            self.tree_helper(res, root->right)

    res = []
    tree_helper(res, root)
    return res


