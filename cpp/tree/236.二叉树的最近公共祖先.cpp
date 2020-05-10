/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 *https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
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
    /**** 方法1:自顶向下*****/
    /*
    从根节点出发， 判断当前节点的左右子树是否包含当前节点
    1、若p、q都在左子树中，则遍历左子树
    2、若p、q都在右子树，则遍历右子树
    3、若p、q分别在左右子树，则返回当前节点
    这种方法，每次递归调用has_node时， 都会遍历一颗子树，重复调用次数较多，O（N^2）
    能AC 但不是好方法
    */
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (has_node(root->left, p) && has_node(root->left, q)) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (has_node(root->right, p) && has_node(root->right, q)) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
    bool has_node(TreeNode* root, TreeNode* target) {
        if (!root) {
            return false;
        }
        if (root == target) {
            return true;
        }
        return has_node(root->left, target) || has_node(root->right, target);
    }

    /**** 方法2:自底向上*****/
    /*
    从根节点出发，直到找到p、q， 然后向上传递
    */
    TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }

    /**** 方法3:数组公共节点*****/
    /*
    dfs 深度遍历二叉树，直到遇到p、q，保留遍历的路径数组
    计算两个数组的公共节点即可
    
    */
    bool flag = false;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        vector<TreeNode*> temp_vec1;
        vector<TreeNode*> temp_vec2;
        bool find1 = dfs(root, temp_vec1, p);
        bool find2 = dfs(root, temp_vec2, q);

        int size = min(temp_vec1.size(), temp_vec2.size());

        // for (auto i = 0; i < temp_vec1.size(); i++) {
        //     cout << temp_vec1[i]->val << "  ";
        // }
        // cout << " | ";
        // for (auto i = 0; i < temp_vec2.size(); i++) {
        //     cout << temp_vec2[i]->val << "  ";
        // }
        TreeNode* result = nullptr;
        if (find1 && find2) {
            for (auto i = 0; i < size; i++) {
                if (temp_vec1[i] != temp_vec2[i]) {
                    break;
                } else {
                    result = temp_vec1[i];
                }
            }
        }

        return result;
    }

    bool dfs(TreeNode* root, vector<TreeNode*>& temp, TreeNode* target) {
        if (root == nullptr) {
            return false;
        }

        temp.push_back(root);
        if (root == target) {
            return true;
        }

        bool find = dfs(root->left, temp, target) || dfs(root->right, temp, target);
        if (find) return true;
        temp.pop_back();
        return false;
    }
};
