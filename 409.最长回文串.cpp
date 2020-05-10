/*
 * @lc app=leetcode.cn id=409 lang=cpp
 * [409] 最长回文串
 * https://leetcode-cn.com/problems/longest-palindrome/description/
 * Easy (50.26%)
 * 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
 * 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
 * 注意:
 * 假设字符串的长度不会超过 1010。
 * 示例 1:
 * 输入:
 * "abccccdd"
 * 输出:
 * 7
 * 解释:
 * 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 *
 *
 */

// @lc code=start
class Solution {
   public:
    /*
    先hash统计字符串中所有字符的个数

    若字符的个数是偶数，则一定可以在回文串中，
    若字符的个数是奇数，则可以将这个奇数字符-1（是偶数） 个字符放到回文串中。同时中心位置可以是一个奇数字符
    */
    int longestPalindrome(string s) {
        int size = s.size();
        if (size <= 1) return size;
        unordered_map<char, int> char_count;
        for (auto& c : s) {
            if (char_count.find(c) != char_count.end()) {
                char_count[c]++;
            } else {
                char_count[c] = 1;
            }
        }
        int result = 0;
        int jishu_count =0;
        int flag = 0;
        for (auto it = char_count.begin(); it != char_count.end(); it++) {
            if (it->second %2 == 0) {// 
                result +=  it->second;
            } else {
                flag = 1;
                result += it->second -1;
            }
        }
        return result + flag;
    }
};
// @lc code=end
