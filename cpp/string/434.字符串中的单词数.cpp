/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 *
 * https://leetcode-cn.com/problems/number-of-segments-in-a-string/description/
 * Easy (32.58%)
 * 统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
 * 请注意，你可以假定字符串里不包括任何不可打印的字符。
 *
 * 示例:
 *
 * 输入: "Hello, my name is John"
 * 输出: 5
 */

// @lc code=start
class Solution {
   public:
    int countSegments(string s) {
        // if (s.find(' ') == s.end()) return 1;
        int start = 0, end = 0;
        int count = 0;
        while (end <= s.size()) {
            if (end == s.size() || s[end] == ' ') {
                if (end > start) count++;
                end++;
                start = end;
            } else {
                end++;
            }
        }
        return count;
    }
};
// @lc code=end
