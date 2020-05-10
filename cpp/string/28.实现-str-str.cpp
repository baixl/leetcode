/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * Easy (39.03%)
 * 实现 strStr() 函数。
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 示例 1:
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 示例 2:
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 *
 * 说明:
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 *
 */

// @lc code=start
class Solution {
   public:
    /*
    暴力法
    */
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;
        if (needle.empty() && needle.empty()) return 0;
        if (needle.empty()) return -1;
        for (auto i = 0; i <= haystack.size() - needle.size(); i++) {
            if (same(haystack.substr(i, needle.size()), needle)) {
                return i;
            }
        }
        return -1;
    }

    bool same(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        int index = 0;
        while (index < s1.size()) {
            if (s1[index] != s2[index]) {
                return false;
            }
            index++;
        }
        return true;
    }

    // 方法2：kmp算法 TODO:
};
// @lc code=end
