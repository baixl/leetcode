/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    // 递归实现
    // 判断 root 的左子树和 root 的右子树 值 是否相等
    bool isSymmetric2(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return symmetric(root->left, root->right);
    }
    bool symmetric(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q== nullptr) { // 都是空
            return true;
        } 
        if (p== nullptr || q== nullptr) { // 只有一个是空
            return false;
        }
        return (p->val == q->val) && symmetric(p->left, q->right) && symmetric(p->right, q->left);
    }

    // 迭代
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        stack<TreeNode *> s;
        TreeNode *p = root->left, *q = root->right;
        s.push(p);
        s.push(q);  
        while (!s.empty()) {
            p = s.top();
            s.pop();
            q = s.top();
            s.pop();

            if (!p && !q) continue;              // p、q都是空节点
            if (!p || !q) return false;          //有一个为空，不对称
            if (p->val != q->val) return false;  //值不相等，不对称

            s.push(p->left);
            s.push(q->right);
            s.push(p->right);
            s.push(q->left);
        }
        return true;
    }
};

