/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */
class Solution {
   public:
    // 逐行 逐列，逐块遍历
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() != 9) {
            return false;
        }
        if (board[0].size() != 9) {
            return false;
        }

        unordered_map<int, int> row[9];
        unordered_map<int, int> column[9];
        unordered_map<int, int> box[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char curr_char = board[i][j];
                if (curr_char == '.') {
                    continue;
                }
                int num = curr_char - '0';

                if (row[i].find(num) != row[i].end()) {
                    return false;
                } else {
                    row[i][num] = 1;
                }

                if (column[j].find(num) != column[j].end()) {
                    return false;
                } else {
                    column[j][num] = 1;
                }
                int box_index = (i / 3) * 3 + j / 3;

                if (box[box_index].find(num) != box[i].end()) {
                    return false;
                } else {
                    box[box_index][num] = 1;
                }
            }
        }
        return true;
    }
};
