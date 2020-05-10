/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
示例 1:
输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 1
示例 2:
输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 3
进阶：
如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？
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
    // 解题思路
    // 1、对二叉搜索树进行遍历，然后排序， 找到第k个元素
    // 2、如何在遍历过程中，就找到第k个元素呢？ 二叉树的中序遍历即可， 二叉搜索树的中序遍历时一颗递增的数
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        int level = 0;
        help(root, result, k, level);

        return result;
    }

    void help(TreeNode* root, int& result, int k, int& level) {
        if (nullptr == root) {
            return;
        }

        if (root->left != nullptr) {
            // level++;
            help(root->left, result, k, level);
        }
        level++;
        if (level == k) {
            result = root->val;
            return;
        }
        if (root->right != nullptr) {
            // level++;
            help(root->right, result, k, level);
        }
    }
};
