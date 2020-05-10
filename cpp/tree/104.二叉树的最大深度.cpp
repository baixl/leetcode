/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    /*
    自顶向下
    */
    int maxDepth2(TreeNode* root) {
        int result = 0;
        if (root == nullptr) return result;
        max_depth(root, result, 1);
        return result;
    }

    void max_depth(TreeNode* root, int& result, int cur_dep) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            result = max(cur_dep, result);
        }
        max_depth(root->left, result, cur_dep + 1);
        max_depth(root->right, result, cur_dep + 1);
    }

    /*
    自底向上
    */
    int maxDepth(TreeNode* root) {
        int result = 0;
        if (root == nullptr) return result;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }

};
