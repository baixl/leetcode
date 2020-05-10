/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int in_size = inorder.size();
        int post_size = postorder.size();
        if (in_size == 0 || in_size != post_size) {
            return nullptr;
        }

        return help(inorder, postorder, 0, in_size - 1, 0, in_size - 1);
    }
    TreeNode* help(vector<int>& inorder, vector<int>& postorder, 
        int in_left, int in_right, 
        int post_left, int post_right) {
        if (in_left < 0 || in_left > in_right 
            || post_right >= postorder.size() 
            || post_left > post_right) {
                return nullptr;
            }
            
        int val = postorder[post_right];
        TreeNode* root = new TreeNode(val);  // 后序遍历的最后一个节点是，二叉树的根节点
        // 然后遍历中序遍历，找到根节点的位置，将中序遍历切分开，然后递归
        for (auto i = in_left; i <= in_right; i++) {
            if (inorder[i] != val) continue;
            root->left = help(inorder, postorder, 
                        in_left, i - 1, post_left, 
                        post_left + i - 1 - in_left);
            root->right = help(inorder, postorder, 
                        i + 1, in_right, 
                        post_right - 1 - (in_right - i - 1), post_right - 1);
        }
        return root;
    }
};
