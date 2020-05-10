/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 * https://leetcode-cn.com/problems/longest-palindromic-subsequence/description/
 * Medium (46.27%)
 * 给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。
 * 示例 1:
 * 输入:
 * "bbbab"
 * 输出:
 * 4
 * 一个可能的最长回文子序列为 "bbbb"。
 * 示例 2:
 * 输入:
 * "cbbd"
 * 输出:
 * 2
 * 一个可能的最长回文子序列为 "bb"。
 */

// @lc code=start
class Solution {
   public:
    /*
    动态规划dp[i][j]表示s[i:j]之间部分的最大子序列长度
    如果两头元素相等则有:
    当s[i] == s[j] dp[i][j] == dp[i+1][j-1] +2;
    如果两头元素不相等，则有：
    当s[i] != s[j] dp[i][j] = max(dp[i+1][j], dp[i][j-1])
    */
    int longestPalindromeSubseq(string s) {
        if (s.empty()) return 0;
        if (s.size() == 1) return 1;
        int size = s.size();

        vector<vector<int>> dp(size, vector<int>(size, 0));
        for (auto i = 0; i < size; i++) {
            dp[i][i] = 1;
        }
        // (i + 1) 表示当前循环的子字符串长度 。 先遍历两个字符，然后3个字符、4个字符...
        for (int i = 1; i < size; i++) {
            // j 表示当前循环的字符串起始坐标
            for (int j = 0; i + j < size; j++) {
                // 即当前循环的子字符串坐标为 [j, i + j]
                // 所以第一个字符是 chars[j]，最后一个字符就是 chars[i + j]
                if (s[j] == s[i + j]) {
                    dp[j][i + j] = dp[j + 1][i + j - 1] + 2;
                } else {
                    dp[j][i + j] = max(dp[j][i + j - 1], dp[j + 1][i + j]);
                }
            }
        }

        return dp[0][size - 1];
    }
};
// @lc code=end
