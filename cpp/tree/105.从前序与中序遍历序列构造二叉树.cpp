/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
根据一棵树的前序遍历与中序遍历构造二叉树。
注意:
你可以假设树中没有重复的元素。
例如，给出
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：
	3
   / \
  9  20
	/  \
   15   7
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
#include <vector>
class Solution {
   public:
	TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
		if (pl > pr || il > ir) {
			return nullptr;
		}
		TreeNode* root = new TreeNode(preorder[pl]);
		for (int i = il; i <= ir; i++) {
			if (preorder[pl] == inorder[i]) {
				if (preorder[pl] == inorder[i]) {
					root->left = build(preorder, inorder, pl + 1, pl + i - il, il, i - 1);
					root->right = build(preorder, inorder, pl + i - il + 1, pr, i + 1, ir);
				}
			}
		}
		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int pre_size = preorder.size();
		int in_size = preorder.size();
		if (pre_size == 0 || in_size == 0) {
			return nullptr;
		}

		return build(preorder, inorder, 0, pre_size - 1, 0, in_size - 1);
	}
};
