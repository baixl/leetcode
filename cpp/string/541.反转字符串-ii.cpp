/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 *
 * https://leetcode-cn.com/problems/reverse-string-ii/description/
 *
 * Easy (49.68%)
 * 给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。如果剩余少于 k
 * 个字符，则将剩余的所有全部反转。如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。
 * 示例:
 * 输入: s = "abcdefg", k = 2
 * 输出: "bacdfeg"
 * 要求:
 * 该字符串只包含小写的英文字母。
 * 给定字符串的长度和 k 在[1, 10000]范围内。
 */

// @lc code=start
class Solution {
   public:
    string reverseStr(string s, int k) {
        if (s.size() <= k) {
            reverse(s.begin(), s.end());
            return s;
        }
        if (s.size() <= 2 * k) {
            reverse(s.begin(), s.begin() + k);
            return s;
        }
        int count = 0;
        auto i = 0;
        for (i = 0; i <= s.size() - k; i += k) {
            if (count % 2 == 0) {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            count++;
        }
        if (count % 2 == 0) {
            reverse(s.begin() + i, s.end());
        }
        return s;
    }
};
// @lc code=end
