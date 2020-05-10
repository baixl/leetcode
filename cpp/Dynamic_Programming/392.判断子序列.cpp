/*
 * @lc app=leetcode.cn id=392 lang=cpp
 * [392] 判断子序列
 * https://leetcode-cn.com/problems/is-subsequence/description/
 *
 * Easy (47.77%)
 * 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
 * 你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。
 * 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。
 * （例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
 * 示例 1:
 * s = "abc", t = "ahbgdc"
 * 返回 true.
 * 示例 2:
 * s = "axc", t = "ahbgdc"
 * 返回 false.
 * 后续挑战 :
 * 如果有大量输入的 S，称作S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T
 * 的子序列。在这种情况下，你会怎样改变代码？
 */

// @lc code=start
class Solution {
   public:
    /*
    解法：
     需要判断s是否为t的子序列，
     1、定义一个index,遍历t，当s[index] == t中的字符时，则index++
     2、当index == s.长度，返回true即可
    */
    bool isSubsequence2(string s, string t) {
        if (s.empty()) return true;
        if (s.size() > t.size()) return false;
        int index = 0;
        for (auto i = 0; i < t.size(); i++) {
            if (s[index] == t[i]) {
                index++;
            }
            if (index == s.size()) return true;
        }
        return false;
    }
    /*
    解法2 动态规划 （这个方法访问超时)
    状态：dp[i][j]为s的从头开始到i的子字符串是否为t从头开始到j的子字符串的子序列
    状态转移公式：
    s[i]==t[j]时，则字符i一定是j的子序列，如果0~i-1子字符串是0~j-1子字符串的子序列，则dp[i][j]=true，所以dp[i][j] =
    dp[i-1][j-1]；
    当char[i]!=char[i]时，即判断当前0~i子字符串是否是0~j-1的子字符串的子序列，即dp[i][j] = dp[i][j -1]。
    如ab，eabc，虽然s的最后一个字符和t中最后一个字符不相等，但是因为ab是eab的子序列，所以ab也是eabc的子序列
    初始化：空字符串一定是t的子字符串的子序列，所以dp[0][j]=true
    */
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        if (s.size() > t.size()) return false;
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(t.size() + 1, false));
        // dp[i][j]表示 s[0:i] 是否t[0:j]的子序列
        // 初始化第1行, s[0:0] 空串
        for (auto j = 0; j <= t.size(); j++) {
            dp[0][j] = true;
        }
        for (auto i = 1; i <= s.size(); i++) {
            for (auto j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return dp[s.size()][t.size()];
    }
};
// @lc code=end
