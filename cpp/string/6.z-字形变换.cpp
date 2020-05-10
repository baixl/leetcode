/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * Medium (45.42%)
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 *
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 请你实现这个将字符串进行指定行数变换的函数：
 * string convert(string s, int numRows);
 * 示例 1:
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 *
 * 示例 2:
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 *
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 *
 */

// @lc code=start
class Solution {
   public:
    // 方法1: 按列打印，使用提个未出现的字符 #， 这里不太严谨
    string convert2(string s, int numRows) {
        int len = s.size();
        if (len <= numRows || numRows <= 1) return s;
        int column = len / (numRows - 1) + 1;
        vector<vector<char>> temp_vec(numRows, vector<char>(column, '#'));
        int godown = 1;
        int index = 0;
        cout << column << " " << numRows;
        for (auto j = 0; j < column; j++) {
            for (auto i = 0; i < numRows; i++) {
                if (index >= s.size()) continue;
                if (godown == 1) {
                    temp_vec[i][j] = s[index];
                    index++;
                } else {
                    if (i == 0 || i == numRows - 1) {
                        continue;
                    }
                    temp_vec[numRows - 1 - i][j] = s[index++];
                }
            }
            godown *= -1;
        }

        string res = "";
        for (auto i = 0; i < numRows; i++) {
            for (auto j = 0; j < column; j++) {
                if (temp_vec[i][j] == '#') continue;
                res += temp_vec[i][j];
            }
        }

        return res;
    }

    // 方法2: 将待打印的字符依次存储到多行
    string convert(string s, int numRows) {
        int len = s.size();
        if (len <= numRows || numRows <= 1) return s;
        vector<string> rows(numRows);
        int curRow = 0;
        bool godown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) godown = !godown;
            curRow += godown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};
// @lc code=end
