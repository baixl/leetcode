/*
 * @lc app=leetcode.cn id=345 lang=cpp
 * easy
 * [345] 反转字符串中的元音字母
 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
示例 1:
输入: "hello"
输出: "holle"
示例 2:
输入: "leetcode"
输出: "leotcede"
说明:
元音字母不包含字母"y"。
 */
class Solution {
   public:
    string reverseVowels(string s) {
        string result;
        if (s.size() <= 1) return s;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !is_yuanyin(s[i])) {
                i++;
            }
            while (i < j && !is_yuanyin(s[j])) {
                j--;
            }
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
    bool is_yuanyin(char c) {
        // 小写字母元音
        bool is_low = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        // 大写字母元音
        bool is_upper = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
        return is_low || is_upper;
    }
};
