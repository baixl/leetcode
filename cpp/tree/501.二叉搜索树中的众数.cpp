/*
 * [501] 二叉搜索树中的众数
 * https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/description/
 * Easy (42.36%)
 * 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
 * 假定 BST 有如下定义：
 * 结点左子树中所含结点的值小于等于当前结点的值
 * 结点右子树中所含结点的值大于等于当前结点的值
 * 左子树和右子树都是二叉搜索树
 * 例如：
 * 给定 BST [1,null,2,2],
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 返回[2].
 * 提示：如果众数超过1个，不需考虑输出顺序
 * 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
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
    /*
    // 方法1： 遍历二叉树， 使用map 的方式存储，保存每个数的数量 需要O(N)空间， 不依赖树的结构
    方法2：二叉搜索树的中序遍历就是递增序列， 只需要依次判断后一个节点的值和前一个是否相等即可
    */
    vector<int> findMode2(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        unordered_map<int, int> map;
        in_order(root, map);
        auto it = map.begin();
        int max_num = INT_MIN;
        for (; it != map.end(); it++) {
            if (it->second > max_num) {
                max_num = it->second;
                res.clear();
                res.push_back(it->first);
            } else if (it->second == max_num) {
                res.push_back(it->first);
            }
        }

        return res;
    }

    void in_order(TreeNode* root, unordered_map<int, int>& map) {
        if (!root) return;
        in_order(root->left, map);
        if (map.find(root->val) != map.end()) {
            map[root->val] += 1;
        } else {
            map[root->val] = 1;
        }
        in_order(root->right, map);
    }
    
    // 方法2: 二叉搜索树的中序遍历就是递增的序列, 不使用
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        in_order_new(root, res);
        return res;
    }
    int pre = INT_MIN;
    int count = 0;
    int max_count = 0;
    void in_order_new(TreeNode* root, vector<int>& res) {
        if (!root) return;
        in_order_new(root->left, res);
        int curr = root->val;
        if (pre == curr) {
            count++;
        } else {
            pre = curr;
            count = 1;
        }
        if (count > max_count) {
            max_count = count;
            res.clear();
            res.push_back(curr);
        } else if (count == max_count) {
            res.push_back(curr);
        }

        in_order_new(root->right, res);
    }
};
