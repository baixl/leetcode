/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        int result = 0;
        if (!root) return result;
        int cur_deep = 0;
        result = INT_MAX;
        dfs(root, result, 1);
        return result;
    }

    void dfs(TreeNode* root, int& result, int cur_deep) {
        if (root->left == nullptr && root->right == nullptr) {
            result = min(result, cur_deep);
        }
        if (root->left) {
            dfs(root->left, result, cur_deep + 1);
        }
        if (root->right) {
            dfs(root->right, result, cur_deep + 1);
        }
    }
};
