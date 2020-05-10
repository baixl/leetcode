/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    // 方法1 递归
    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> result;
        in_oerder(root, result);
        return result;
    }
    void in_oerder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        if (root->left != nullptr) {
            in_oerder(root->left, result);
        }
        result.push_back(root->val);
        if (root->right != nullptr) {
            in_oerder(root->right, result);
        }
    }
    // 方法2：迭代
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        stack<TreeNode*> s;
        TreeNode* node = root;
        while (node != nullptr || !s.empty()) {
            if (node != nullptr) {
                s.push(node);
                node = node->left;  // 一直遍历到最左边
            } else {
                node = s.top();
                s.pop();
                result.push_back(node->val);
                node = node->right;
            }
        }
        return result;
    }
};
