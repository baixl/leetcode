/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 * Easy (59.84%)
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 说明: 叶子节点是指没有子节点的节点。
 * 示例:
 * 输入:
 *
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 *
 * 输出: ["1->2->5", "1->3"]
 *
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (nullptr == root) return res;
        string s;
        dfs(root, res, s);
        return res;
    }
    void dfs(TreeNode* root, vector<string>& res, string s) {
        if (nullptr == root) return;
        if (nullptr == root->left && nullptr == root->right) {
            s += "->" + to_string(root->val);
            res.push_back(s.substr(2, s.size()-2));
        }
        s += "->" + to_string(root->val);
        if (root->left) dfs(root->left, res, s);
        if (root->right) dfs(root->right, res, s);
    }
};
