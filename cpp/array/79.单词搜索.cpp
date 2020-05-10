/*
 * @lc app=leetcode.cn id=79 lang=cpp
 * [79] 单词搜索
 * https://leetcode-cn.com/problems/word-search/description/
 * Medium (39.05%)
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 示例:
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 *
 * 给定 word = "ABCCED", 返回 true.
 * 给定 word = "SEE", 返回 true.
 * 给定 word = "ABCB", 返回 false.
 *
 */
class Solution {
   public:
    // 相似题目：212 单词搜索II
    /*
    解法：回溯+递归
    1、遍历字母矩阵，找到一个和字符串首字母相等的字符，然后按照上下左右4个方向，找到和字符串第2个字母相同的位置
    然后依次
    2、递归时需要注意以遍历的节点要剔除在外
    */
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty()) return false;
        int row = board.size(), col = board[0].size();
        // 如果矩阵中的字母个数< 字符串长度，直接返回
        if (row * col < word.size()) return false; 

        vector<vector<int>> visited(row, vector<int>(col, 0));
        for (auto i = 0; i < row; i++) {
            for (auto j = 0; j < col; j++) {
                bool res = find(board, i, j, word, 0, visited);
                if (res) return res;
            }
        }
        return false;
    }

    bool find(vector<vector<char>>& board, int i, int j, string& word, int start, vector<vector<int>>& visited) {
        
        if (start == word.size()) return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[start]) {
            return false;
        }
        if (visited[i][j] ==1)  return false; // 已方问过， 还有一种处理是将已访问过的字符设置成一个不常见字符，但这种处理不太严谨

        visited[i][j] = 1;  // 已访问， 用于回溯的标记
        bool res = find(board, i - 1, j, word, start + 1, visited) 
            || find(board, i + 1, j, word, start + 1, visited) 
            || find(board, i, j - 1, word, start + 1, visited) 
            || find(board, i, j + 1, word, start + 1, visited);

        visited[i][j] = 0;  // 清空回溯标记
        return res;
    }
};
