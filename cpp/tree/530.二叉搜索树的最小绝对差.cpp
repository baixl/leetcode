/*
 * [530] 二叉搜索树的最小绝对差
 * https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/description/
 * Easy (54.31%)
 * 给定一个所有节点为非负值的二叉搜索树，求树中任意两节点的差的绝对值的最小值。
 * 示例 :
 * 输入:
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 * 输出: 1
 * 解释:
 * 最小绝对差为1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
 * 注意: 树中至少有2个节点。
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
    // 二叉搜索树 中序遍历为递增序列， 依次比较遍历中的前后两个元素即可
    int pre = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        if (!root) return 0;
        int result = INT_MAX;
        in_order(root, result);
        return result;
    }

    void in_order(TreeNode* root, int& result) {
        if (!root) return;
        in_order(root->left, result);
        int cur_val = root->val;
        if (pre != INT_MAX) {  // 排除第一个pre
            result = min(result, cur_val - pre);
        }
        pre = cur_val;

        in_order(root->right, result);
    }
};
