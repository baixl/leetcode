/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() -1);
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int start , int end) {
        if (start > end) {
            return nullptr;
        }
        int mid  = start +(end - start) / 2;
        TreeNode* p = new TreeNode(nums[mid]);
        p->left= sortedArrayToBST(nums, start, mid-1);
        p->right= sortedArrayToBST(nums, mid+1, end);
        return  p;
    }
};

