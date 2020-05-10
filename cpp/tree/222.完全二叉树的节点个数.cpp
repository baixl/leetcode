/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    // 层序遍历
    int countNodes2(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int result = 0;
        while (!q.empty()) {
            int size = q.size();
            result += size;
            for (auto i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return result;
    }
    // 二叉树的先序遍历，节点个数
    int countNodes(TreeNode* root) {
        int result = 0;
        pre_oder(root, result);
        return result;
    }

    void pre_oder(TreeNode* root, int& result) {
        if (!root) return;
        result++;
        pre_oder(root->left, result);
        pre_oder(root->right, result);
    }
};
