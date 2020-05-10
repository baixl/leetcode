/*
 * [404] 左叶子之和
 * https://leetcode-cn.com/problems/sum-of-left-leaves/description/
 * Easy (51.57%)
 * 计算给定二叉树的所有左叶子之和。
 * 示例：
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    int res = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return res;
        dfs(root, false);
        return res;
    }

    void dfs(TreeNode* root, bool is_left) {
        if (!root->left && !root->right) {
            if (is_left) res += root->val;
        }
        if (root->left) {
            dfs(root->left, true);
        }
        if (root->right) {
            dfs(root->right, false);
        }
    }
};
