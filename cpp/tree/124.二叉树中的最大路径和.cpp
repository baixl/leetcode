/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (37.87%)
 * Likes:    294
 * Dislikes: 0
 * Total Accepted:    22.9K
 * Total Submissions: 58.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个非空二叉树，返回其最大路径和。
 * 
 * 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * 输出: 6
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * 输出: 42
 * 
 */

// @lc code=start
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
    int maxPathSum(TreeNode* root) {
        if (nullptr == root)  return 0;
        int result = INT_MIN;
        help(root, result);
        return result;
    }

    int help(TreeNode* root, int& result) {
        if (nullptr == root)  return 0;
        
        int left = help(root->left, result);
        left = max(0, left); // 避免分支路径和为负
        int right = help(root->right, result);
        right = max(0, right);
        int cur = root->val + left + right;
        result = max(result, cur);
        return root->val + max(left, right);  // 向上传递， 一定是过了当前节点，此时不可能包含左右两个分支
    }
};
// @lc code=end

