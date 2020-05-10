/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
例如：
给定二叉树 [3,9,20,null,null,15,7],
		3
   / \
  9  20
		/  \
   15   7
返回锯齿形层次遍历如下：
[
  [3],
  [20,9],
  [15,7]
]
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
#include <stack>
class Solution {
   public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (root == nullptr) {
			return result;
		}
		queue<TreeNode*> q;
		q.push(root);
		int level = 0;
		while (!q.empty()) {
			vector<int> temp_vec;  // 记录每一层元素
			int level_size = q.size();
			for (int i = 0; i < level_size; i++) {
				TreeNode* temp = q.front();
				q.pop();
				temp_vec.push_back(temp->val);
				if (temp->left) {
					q.push(temp->left);
				}
				if (temp->right) {
					q.push(temp->right);
				}
			}
			level += 1;
			if (level % 2 == 0) {
				reverse(temp_vec.begin(), temp_vec.end());
			}
			result.push_back(temp_vec);
		}
		return result;
	}
};
