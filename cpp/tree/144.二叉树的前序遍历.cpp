/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
#include <stack>
class Solution {
   public:
    /*
    递归
    */
    vector<int> preorderTraversal2(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }

    void preorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }

    /*
    非递归
    非递归需要使用栈， 先进后出， 则进栈顺序，
    1、开始将根节点进栈
    2、先将右子节点
    */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            result.push_back(node->val);
            s.pop();
            if (node->right) {
                s.push(node->right);
            }
            if (node->left) {
                s.push(node->left);
            }
        }
        return result;
    }
};
