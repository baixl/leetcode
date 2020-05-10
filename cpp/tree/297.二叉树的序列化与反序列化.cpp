/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
class Codec {
   public:
    // 使用二叉树的先序遍历，
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        write(root, s);
        return s;
    }

    void write(TreeNode* root, string& s) {
        if (!root) {
            s += "# ";
            return;
        }
        s += to_string(root->val) + ' ';
        write(root->left, s);
        write(root->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return read(data, pos);
    }

    TreeNode* read(string data, int& pos) {
        if (data[pos] == '#') {
            pos += 2;
            return nullptr;
        }
        int num = 0;
        int fuhao = 1;
        while (data[pos] != ' ') {
            if (data[pos] == '-') {
                fuhao = -1;
                pos++;
            } else {
                num = num * 10 + data[pos] - '0';
                pos++;
            }
        }
        TreeNode* nowNode = new TreeNode(num * fuhao);
        pos++;
        nowNode->left = read(data, pos);
        nowNode->right = read(data, pos);
        return nowNode;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
