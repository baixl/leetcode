/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> cur_vec;
            for (auto i = 0; i < size; i++) {
                TreeNode* node = q.front();
                cur_vec.push_back(node->val);
                 q.pop();
                 if (node->left) {
                     q.push(node->left);
                 }
                 if (node->right){
                     q.push(node->right);
                 }
            }
            result.insert(result.begin(), cur_vec);
        }
        return result;
    }
};
