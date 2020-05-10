/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
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
    // 常数空间
    // 先
    Node* connect(Node* root) {
        if (!root) return nullptr;
        Node* p = root->next;
        while (p) {
            if (p->left) {  // 有左子节点
                p = p->left;
                break;
            }
            if (p->right) {  // 有右子节点
                p = p->right;
                break;
            }
            p = p->next;  // 没有左右子节点，继续往后走
        }
        if (root->right) root->right->next = p;
        if (root->left) root->left->next = root->right ? root->right : p;
        connect(root->right);
        connect(root->left);
        return root;
    }
    // 使用一个辅助队列
    Node* connect2(Node* root) {
        if (!root) {
            return root;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            Node* pre = nullptr;
            for (auto i = 0; i < size; i++) {
                Node* cur = q.front();
                q.pop();
                if (i > 0) {
                    pre->next = cur;
                }
                pre = cur;
                if (cur->left != nullptr) {
                    q.push(cur->left);
                }
                if (cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
        }
        return root;
    }
};
