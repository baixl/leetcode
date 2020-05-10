/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 * https://leetcode-cn.com/problems/implement-trie-prefix-tree/description/
 *
 * Medium (61.32%)
 * 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
 * 示例:
 * Trie trie = new Trie();
 *
 * trie.insert("apple");
 * trie.search("apple");   // 返回 true
 * trie.search("app");     // 返回 false
 * trie.startsWith("app"); // 返回 true
 * trie.insert("app");
 * trie.search("app");     // 返回 true
 *
 * 说明:
 *
 * 你可以假设所有的输入都是由小写字母 a-z 构成的。
 * 保证所有输入均为非空字符串。
 */
/*
https://blog.csdn.net/qq_33297776/article/details/82315859
*/
class Node {
   public:
    int val;          // 当前结束的字符，字符串出现的次数
    Node* child[26];  // 26个子节点，（a-z）共26个字母
    Node() {
        val = 0;
        for (auto i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};
class Trie {
   public:
    /** Initialize your data structure here. */
    Node* root;  // 根据节点
    Trie() { root = new Node(); }
    // 前缀树的插入
    void insert(string word) {
        Node* p = root;
        for (auto i = 0; i < word.size(); i++) {
            if (p->child[word[i] - 'a'] == nullptr) {  // 若child 没出现过该字符，则新建节点
                p->child[word[i] - 'a'] = new Node();
            }
            p = p->child[word[i] - 'a'];
        }
        p->val++;  // 更新当前结束的字符时， 字符串出现的次数
    }

    bool search(string word) {
        Node* p = root;
        for (auto i = 0; i < word.size(); i++) {
            if (p->child[word[i] - 'a'] == nullptr) {
                return false;
            } else {
                p = p->child[word[i] - 'a'];
            }
        }
        if (p->val != 0) {  // 是出现过的字符串
            return true;
        } else {
            return false;
        }
    }

    bool startsWith(string prefix) {
        Node* p = root;
        for (auto i = 0; i < prefix.size(); i++) {
            if (p->child[prefix[i] - 'a'] == nullptr) {
                return false;
            } else {
                p = p->child[prefix[i] - 'a'];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
