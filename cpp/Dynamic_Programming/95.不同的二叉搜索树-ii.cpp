/*
 * [95] 不同的二叉搜索树 II
给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
示例:
输入: 3
输出:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释:
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
   // 官方题解 https://leetcode-cn.com/problems/unique-binary-search-trees-ii/solution/bu-tong-de-er-cha-sou-suo-shu-ii-by-leetcode/
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> result;
        if (n <= 0) {
            return result;
        }
        result = create_tree(1, n);
        return result;
    }
    vector<TreeNode *> create_tree(int start, int end) {
        vector<TreeNode *> result;
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }
        if (start == end) {
            result.push_back(new TreeNode(start));
            return result;
        }

        for (int i = start; i <= end; i++) {
            vector<TreeNode *> left = create_tree(start, i - 1);
            vector<TreeNode *> right = create_tree(i + 1, end);
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode *node = new TreeNode(i);
                    node->left = left[j];
                    node->right = right[k];
                    result.push_back(node);
                }
            }
        }
        return result;
    }
};
