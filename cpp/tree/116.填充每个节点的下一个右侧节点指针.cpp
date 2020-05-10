/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
   public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        conect_node(root);
        return root;
    }
    /*
    直接看代码吧
    */
    void conect_node(Node* node) {
        if (node->left == nullptr || node->right == nullptr) {
            return;
        }
        node->left->next = node->right;
        if (node->next != nullptr) {
            node->right->next = node->next->left;
        }
        connect(node->left);
        connect(node->right);
    }
};
