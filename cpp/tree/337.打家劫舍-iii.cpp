/*
 * [337] 打家劫舍 III
 * https://leetcode-cn.com/problems/house-robber-iii/description/
 * Medium (54.20%)
 *
 在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。
 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
 * 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
 * 计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
 * 示例 1:
 * 输入: [3,2,3,null,3,null,1]
 * ⁠    3
 * ⁠   / \
 * ⁠  2   3
 * ⁠   \   \
 * ⁠    3   1
 * 输出: 7
 * 解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.

 * 示例 2:
 * 输入: [3,4,5,1,3,null,1]
 *     3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \   \
 * ⁠1   3   1
 * 输出: 9
 * 解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
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
    /*
    递归动态规划
    超时
    */
    int rob2(TreeNode* root) {
        if (!root) return 0;
        int left = rob(root->left);
        int right = rob(root->right);

        int left_child_child = 0;
        int right_child_child = 0;
        if (root->left) {
            left_child_child = rob(root->left->left) + rob(root->left->right);
        }
        if (root->right) {
            right_child_child =
                rob(root->right->left) + rob(root->right->right);
        }
        return max(root->val + left_child_child + right_child_child,
                   left + right);
    }
    // 动态规划+ map 缓存
    unordered_map<TreeNode*, int> map;
    int rob3(TreeNode* root) {
        if (!root) return 0;
        int left = rob(root->left);
        int right = rob(root->right);
        map[root->left] = left;
        map[root->right] = right;
        int left_child_child = 0;
        int right_child_child = 0;
        if (root->left) {
            left_child_child = map[root->left->left] + map[root->left->right];
        }
        if (root->right) {
            right_child_child =
                map[root->right->left] + map[root->right->right];
        }
        int res =
            max(root->val + left_child_child + right_child_child, left + right);
        map[root] = res;
        return res;
    }

    // 动态规划，不适用额外空间
    int res = 0;
    int rob(TreeNode* root) {
        if (!root) return res;
        dfs(root);
        return res;
    }

    // 动态规划： 每个节点有两种方案，选择该节点 和不选该节点
    // vector[0] 不选根节点的max， vector[1]选根节点 的max
    vector<int> dfs(TreeNode* root) {
        if (!root) {
            return vector<int>{0, 0};
        }
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        // 更新当前节点的值
        vector<int> temp(2, 0);
        temp[0] = max(left[0], left[1]) + max(right[0], right[1]);
        temp[1] = root->val + left[0] + right[0];
        res = max(res, max(temp[0], temp[1]));
        return temp;
    }
};
