/*
 * @lc app=leetcode.cn id=212 lang=cpp
 * [212] 单词搜索 II
 * https://leetcode-cn.com/problems/word-search-ii/description/
 * Hard (36.20%)
 *
 * 给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
 *
 * 示例:
 * 输入:
 * words = ["oath","pea","eat","rain"] and board =
 * [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 *
 * 输出: ["eat","oath"]
 *
 * 说明:
 * 你可以假设所有输入都由小写字母 a-z 组成。
 *
 * 提示:
 *
 * 你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
 * 如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？
 * 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。
 *
 *
 */
//********************** 构造前缀树
// 前缀树节点
class TrieNode {
   public:
    bool isWord;
    vector<TrieNode*> child;
    string word;  //
    TrieNode() {
        isWord = false;
        child = vector<TrieNode*>(26, nullptr);
        word = "";
    }
};
class Trie {
   public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    // 前缀树插入字符串
    void insert(string s) {
        TrieNode* node = root;
        for (auto i = 0; i < s.size(); i++) {
            if (node->child[s[i] - 'a'] == nullptr) {
                node->child[s[i] - 'a'] = new TrieNode();
            }
            node = node->child[s[i] - 'a'];
        }
       
        node->isWord = true;
        node->word = s;
    }
    // 字符串是否在前缀树中
    bool search(string s) {
        TrieNode* node = root;
        for (auto i = 0; i < s.size(); i++) {
            if (node->child[s[i] - 'a'] == nullptr) return false;
            node = node->child[s[i] - 'a'];
        }
        return node->isWord;
    }

    bool isPre(string s) {
        TrieNode* node = root;
        for (auto i = 0; i < s.size(); i++) {
            if (node->child[s[i] - 'a'] == nullptr) return false;
            node = node->child[s[i] - 'a'];
        }
        return true;
    }
};
//********************** 构造前缀树

class Solution {
   public:
    /*
    相似题目：79 单词搜索（回溯+递归）
    方法1： 最简单的方法是 按照79题的方式，组个判断字符串是否出现在字典中，这样会存在大量的重复计算，复杂度过高。
    方法2： 参考208，使用前缀树来实现，前缀树的查找效率比较高。
    1、先用给定的字符串数组构建前缀树
    2、回溯的方式遍历字典（矩阵），当发现以当前字符结尾的字符串在前缀树中，则加入结果候选集
    */
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || words.empty()) return {};
        Trie* trie = new Trie();
        for (auto s : words) {
            trie->insert(s);
        }
        //-- 遍历词典
        int row = board.size(), column = board[0].size();
        unordered_set<string> res;  // 避免重复
        vector<vector<bool>> visited(row, vector<bool>(column, false));

        for (auto i = 0; i < row; i++) {
            for (auto j = 0; j < column; j++) {
                // back_trace(board, visited, i, j, trie->root, res);
                back_trace(board, i, j, trie->root, res);
            }
        }
        
        vector<string> result;
        for (auto s: res) {
            result.push_back(s);
        }
        return result; 
    }
    void back_trace(vector<vector<char>>& board, 
        // vector<vector<bool>>& visited, 
        int i, int j, 
        TrieNode* node,
        unordered_set<string>& res) {
        int row = board.size(), column = board[0].size();

        
        if (i < 0 || i >= row || j < 0 || j >= column || board[i][j] == '#') return;
        if (node == nullptr) return;
        node = node->child[board[i][j] - 'a'];
        if (node == nullptr) return;

        if (node->isWord && node->word != "") {
            res.insert(node->word);
        }

        char ch = board[i][j];
        board[i][j] = '#';
        back_trace(board,  i - 1, j, node, res);
        back_trace(board, i + 1, j, node, res);
        back_trace(board, i, j - 1, node, res);
        back_trace(board, i, j + 1, node, res);
        board[i][j] = ch;
    }
};
