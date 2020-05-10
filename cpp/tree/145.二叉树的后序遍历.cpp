/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    递归
    */
    vector<int> postorderTraversal1(TreeNode* root) {
        vector<int> res;
        post_order(root, res);
        return res;
    }
    void post_order(TreeNode* root, vector<int>& res) {
        if (!root) return;

        post_order(root->left, res);
        post_order(root->right, res);
        res.push_back(root->val);
    }
    /*
    非递归，方法1：
    二叉树的前序遍历顺序是： 中-> 左->右
    二叉树的后序遍历顺序是： 左->右 -> 中
    于是可以把二叉树的前序遍历顺序交换下 ->  中-> 右-> 左
    然后在转置一下数组 就是   左->右 -> 中
    */
    vector<int> postorderTraversal2(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            result.push_back(node->val);
            s.pop();
            if (node->left != nullptr) {  // 前序遍历这里是先入栈右子节点
                s.push(node->left);
            }
            if (node->right != nullptr) {
                s.push(node->right);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
    /*
    非递归，方法2：
    入栈顺序不变，我们只需要考虑第3点的变化（合适时机转向）。出栈的对象一定都是“左”节点（“右”节点会在转向后称为“左”节点，然后入栈），也就是实际的左或根；实际的左可以当做左右子树都为null的根，所以我们只需要分析实际的根。
    对于实际的根，需要保证先后访问了左子树、右子树之后，才能访问根。实际的右节点、左节点、根节点都会成为“左”节点入栈，所以我们只需要在出栈之前，将该节点视作实际的根节点，并检查其右子树是否已被访问即可。
    如果不存在右子树，或右子树已被访问了，那么可以访问根节点，出栈，并不需要转向；
    如果还没有访问，就转向，使其“右”节点成为“左”节点，等着它先被访问之后，再来访问根节点。
    所以，我们需要增加一个标志，记录右子树的访问情况。由于访问根节点前，一定先紧挨着访问了其右子树，所以我们只需要一个标志位。
    */
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> s;
        TreeNode* node = root;
        TreeNode* last = nullptr;
        while (node != nullptr || !s.empty()) {
            while (node != nullptr) {
                s.push(node);
                node = node->left;  // 最左边叶子节点
            }
            node = s.top();
            if (node->right == nullptr || node->right == last) {
                result.push_back(node->val);
                s.pop();
                last = node;
                node = nullptr;
            } else {
                node = node->right;
            }
        }

        return result;
    }
};
