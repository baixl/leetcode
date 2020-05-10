/*
 * [110] 平衡二叉树
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 * Easy (49.06%)
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 本题中，一棵高度平衡二叉树定义为：
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
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
    自顶向下 依次求左右子树的深度来解决
    每个节点计算深度时有重复，整体复杂度较高O(n^2)
    */
    bool isBalanced2(TreeNode* root) {
        if (!root) return true;
        int left = depth(root->left);
        int right = depth(root->right);
        if (abs(depth(root->left) - depth(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int depth(TreeNode* root) {
        if (!root) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
    /*
    自底向上O(n)
    */
    bool isBalanced(TreeNode* root) { return help(root) != -1; }

    int help(TreeNode* root) {
        if (nullptr == root) return 0;
        int left = help(root->left);
        if (left == -1) return -1;
        int right = help(root->right);
        if (right == -1) return -1;
        return abs(left - right) <= 1 ? max(left, right) + 1 : -1;
    }
};
