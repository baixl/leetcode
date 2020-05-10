/*
[113] 路径总和 II
 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
说明: 叶子节点是指没有子节点的节点。
示例:
给定如下二叉树，以及目标和 sum = 22，
			  5
			 / \
			4   8
		   /   / \
		  11  13  4
		 /  \    / \
		7    2  5   1
返回:
[
   [5,4,11,2],
   [5,8,4,5]
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
class Solution {
   public:
	void help(TreeNode* root, int sum, vector<int>& temp_vec, vector<vector<int>>& result) {
		if (root == nullptr) {
			return;
		}
		int val = root->val;
		temp_vec.push_back(val);
		if (root->left == nullptr && root->right == nullptr) {
			if (val == sum) {
				result.push_back(temp_vec);
			}
		}
		help(root->left, sum - val, temp_vec, result);
		help(root->right, sum - val, temp_vec, result);
		temp_vec.pop_back();
	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		if (root == nullptr) {
			return result;
		}
		vector<int> temp_vec;
		help(root, sum, temp_vec, result);
		return result;
	}
};
