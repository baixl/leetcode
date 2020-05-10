/*
 * [543] 二叉树的直径
 * https://leetcode-cn.com/problems/diameter-of-binary-tree/description/
 * Easy (46.02%)
 * 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。
 * 示例 :
 * 给定二叉树
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \
 * ⁠     4   5
 * 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
 * 注意：两结点之间的路径长度是以它们之间边的数目表示。
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
    // 一个节点的直径 = 左子树的高度 + 右子树的高度，
    // 遍历每个节点 找到所有节点的直径最大值即可
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return 0;
        int result = INT_MIN;
        depth(root, result);
        return result;
    }

    int depth(TreeNode* root, int& result) {
        if (!root) return 0;
        int left = depth(root->left, result);
        int right = depth(root->right, result);
        result = max(result, left + right);
        return max(left, right) + 1;
    }
};
