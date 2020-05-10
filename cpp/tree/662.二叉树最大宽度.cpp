/*
 * [662] 二叉树最大宽度
 * https://leetcode-cn.com/problems/maximum-width-of-binary-tree/description/
 * Medium (33.29%)
 * 给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。这个二叉树与满二叉树（full binary
 * tree）结构相同，但一些节点为空。
 * 每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。
 * 示例 1:
 * 输入:
 * ⁠          1
 * ⁠        /   \
 * ⁠       3     2
 * ⁠      / \     \
 * ⁠     5   3     9
 * 输出: 4
 * 解释: 最大值出现在树的第 3 层，宽度为 4 (5,3,null,9)。
 * 示例 2:
 * 输入:
 * ⁠         1
 * ⁠        /
 * ⁠       3
 * ⁠      / \
 * ⁠     5   3
 * 输出: 2
 * 解释: 最大值出现在树的第 3 层，宽度为 2 (5,3)。
 * 示例 3:
 * 输入:
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      /
 * ⁠     5
 *
 * 输出: 2
 * 解释: 最大值出现在树的第 2 层，宽度为 2 (3,2)。
 * 示例 4:
 * 输入:
 *
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      /     \
 * ⁠     5       9
 * ⁠    /         \
 * ⁠   6           7
 * 输出: 8
 * 解释: 最大值出现在树的第 4 层，宽度为 8 (6,null,null,null,null,null,null,7)。
 *
 * 注意: 答案在32位有符号整数的表示范围内。
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
    对二叉树的节点进行编号进行计算：
    例如一个树的节点编号为：
      ⁠      0
  ⁠        /   \
  ⁠       1     2
  ⁠      / \   / \
  ⁠     3   4  5  6
    左子节点编号= 父节点编号*2 + 1 右子节点编号= 父节点编号*2 + 2
    依据这个规则，层次遍历进行计算。 和普通层次遍历不同的是，这里，在层次遍历时，还需要保留节点的编号
    层次遍历的队列存放<节点, 编号> 这样的pair对来解决

     */
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        int result = 0;
        while (!q.empty()) {
            int size = q.size();
            if (size == 1) {  // 只有一个节点
                q.front().second = 0;
            }
            int left = q.front().second, right = left;

            for (auto i = 0; i < size; i++) {
                TreeNode* node = q.front().first;  // 节点
                right = q.front().second;          // 节点的编号
                q.pop();

                if (node->left) {
                    q.push(make_pair(node->left, right * 2 + 1));
                }
                if (node->right) {
                    q.push(make_pair(node->right, right * 2 + 2));
                }
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
