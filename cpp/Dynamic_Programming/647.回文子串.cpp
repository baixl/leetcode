/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 *
 * https://leetcode-cn.com/problems/palindromic-substrings/description/
 *
 * Medium (60.67%)
 * 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。
 * 示例 1:
 *
 *
 * 输入: "abc"
 * 输出: 3
 * 解释: 三个回文子串: "a", "b", "c".
 *
 *
 * 示例 2:
 *
 *
 * 输入: "aaa"
 * 输出: 6
 * 说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".
 *
 *
 * 注意:
 *
 *
 * 输入的字符串长度不会超过1000。
 *
 *
 */

// @lc code=start
class Solution {
   public:
    //使用动态规划  dp[i][j]表示 s[i]--s[j]是否是回文子串
    //状态转移方程：dp[i][j] = dp[i+1][j-1] && str[i]==str[j]

    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int res = 0;
        for (auto i = 0; i < s.size(); i++) {
            for (auto j = i; j >= 0; j--) {
                if (s[j] == s[i] && (i - j < 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    res++;
                }
            }
        }
        return res;
    }
};

// @lc code=end
