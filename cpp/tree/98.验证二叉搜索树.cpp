/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    // 转化成二叉树的中序遍历
    bool isValidBST(TreeNode* root) {
        vector<int> mid_vec; // 二叉树中序遍历数组
        help(root, mid_vec);
        for(int i = 1; i< mid_vec.size(); i++) {
            if (mid_vec[i] <= mid_vec[i-1]){
                return false;
            }
        }
        return true;
        
    }
    void help(TreeNode * root, vector<int> & result){
        if(root ==nullptr) return;
       
        if(root->left) help(root->left, result);
        result.push_back(root->val);
        if(root->right) help(root->right, result);
    }

};

