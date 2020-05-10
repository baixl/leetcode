/*
 * [637] 二叉树的层平均值
 * https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/description/
 *
 * Easy (60.93%)
 * 给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.
 * 示例 1:
 * 输入:
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 输出: [3, 14.5, 11]
 * 解释:
 * 第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
 * 注意：
 * 节点值的范围在32位有符号整数范围内。
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            long sum = 0;
            for (auto i = 0; i < size; i++) {
                TreeNode* node = q.front();
                sum += node->val;
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(static_cast<double>(sum) / size);
        }
        return res;
    }
};
