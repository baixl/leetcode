/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 *
 * https://leetcode-cn.com/problems/distinct-subsequences/description/
 *
 * Hard (44.67%)
 * 给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数。
 * 一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE"
 * 的一个子序列，而 "AEC" 不是）
 * 示例 1:
 *
 * 输入: S = "rabbbit", T = "rabbit"
 * 输出: 3
 * 解释:
 *
 * 如下图所示, 有 3 种可以从 S 中得到 "rabbit" 的方案。
 * (上箭头符号 ^ 表示选取的字母)
 *
 * rabbbit
 * ^^^^ ^^
 * rabbbit
 * ^^ ^^^^
 * rabbbit
 * ^^^ ^^^
 *
 *
 * 示例 2:
 *
 * 输入: S = "babgbag", T = "bag"
 * 输出: 5
 * 解释:
 *
 * 如下图所示, 有 5 种可以从 S 中得到 "bag" 的方案。
 * (上箭头符号 ^ 表示选取的字母)
 *
 * babgbag
 * ^^ ^
 * babgbag
 * ^^    ^
 * babgbag
 * ^    ^^
 * babgbag
 * ⁠ ^  ^^
 * babgbag
 * ⁠   ^^^
 *
 */

// @lc code=start
class Solution {
   public:
    /*
    动态规划:
    dp[i][j] :i  j 代表 t s 两个字符串的长度，
    dp[i][j]表示，字符串s[0...j]的子序列包含t[0...i] 的个数
    当t[i] != s[j]:
            dp[i][j] = dp[i][j-1];// s增加一个字符也没用
    当t[i] == s[j]:
            dp[i][j] = dp[i-1][j-1] + dp[i]j-1]
            dp[i-1][j-1] 表示s[i]和t[j]固定匹配
            dp[i]j-1] 表示s[i]和t[j]不匹配时， t[0...j-1]子序列包含s[i]的个数
    当t为空时，默认返回1， 则dp[0][j] =1
     */
    int numDistinct(string s, string t) {
        if (s.empty()) return 0;
        if (t.empty()) return 1;
        int m = t.size();
        int n = s.size();
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
        for (auto i = 0; i < n; i++) {
            dp[0][i] = 1;
        }
        for (auto i = 1; i < m + 1; i++) {
            for (auto j = 1; j < n + 1; j++) {
                if (t[i - 1] != s[j - 1]) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
