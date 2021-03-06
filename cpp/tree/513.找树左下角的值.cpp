/*
 * [513] 找树左下角的值
 * https://leetcode-cn.com/problems/find-bottom-left-tree-value/description/
 * Medium (66.80%)
 * 给定一个二叉树，在树的最后一行找到最左边的值。
 * 示例 1:
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 输出:
 * 1
 * 示例 2:
 * 输入:
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   5   6
 * ⁠      /
 * ⁠     7
 * 输出:
 * 7
 * 注意: 您可以假设树（即给定的根节点）不为 NULL。
 *
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
    int findBottomLeftValue(TreeNode* root) {
        if (!root) return INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        int result = 0;
        while (!q.empty()) {
            int size = q.size();
            result = q.front()->val;
            for (auto i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
             }
        }
        return result;
    }
};
