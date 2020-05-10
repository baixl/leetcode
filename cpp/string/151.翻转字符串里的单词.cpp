/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 * https://leetcode-cn.com/problems/reverse-words-in-a-string/description/
 *
 * Medium (32.40%)
 * 给定一个字符串，逐个翻转字符串中的每个单词。
 *
 * 示例 1：
 * 输入: "the sky is blue"
 * 输出: "blue is sky the"
 * 示例 2：
 * 输入: "  hello world!  "
 * 输出: "world! hello"
 * 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 *
 * 示例 3：
 * 输入: "a good   example"
 * 输出: "example good a"
 * 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 *
 * 说明：
 *
 * 无空格字符构成一个单词。
 * 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 *
 * 进阶：
 * 请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。
 */

// @lc code=start
class Solution {
   public:
    /*
    先翻转整个字符串，然后翻转每个子字符串
    */
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int start = 0, end = 0;
        while (end < s.size() && s[end] == ' ') {
            end++;
            start++;
        }

        string res = "";
        string temp = "";
        while (end <= s.size()) {
            if (end == s.size() || s[end] == ' ') {
                if (end > start) {
                    temp = s.substr(start, end - start);
                    reverse(temp.begin(), temp.end());
                    res += temp + " ";
                }
                start = end;
                end++;
                start++;
            } else {
                end++;
            }
        }
        if (res[res.size() - 1] == ' ') res = res.substr(0, res.size() - 1);
        return res;
    }
};
// @lc code=end
