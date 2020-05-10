/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * [5] 最长回文子串
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * Medium (27.50%)
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 示例 1：
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 示例 2：
 * 输入: "cbbd"
 * 输出: "bb"
 */

// @lc code=start
class Solution {
   public:
    /*
    相关题目：516 最长回文子序列
    方法1：动态规划
    方法2：中心扩展
    方法3：manacher算法
    */
    /********************
     * 方法1： 动态规划法
     * 设函数f(i,j) 表示字符串s[i:j]是回文字符串，则有
     * f(i,j) == 1 当 i==j
     * f(i,j) ==1 当j == i+1 && s[j] ==s[i]
     * f(i,j) ==1 当 s[i]==s[j] && f(i+1, j-1) == 1
     */
    string longestPalindrome1(string s) {
        if (s.empty()) return "";
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int start = 0, len = 0;
        for (int j = 0; j < s.size(); j++) {
            int i = 0;
            dp[j][j] = true;
            //一个元素肯定是回文串。
            for (; i <= j; i++) {
                dp[i][j] = (s[j] == s[i] && (j - i < 2 || j > 0 && dp[i + 1][j - 1]));
                //如果s[j]==s[i]当串的长度小于等于2时，肯定是回文子串，如a aa，就是回文串。
                //如果长度大于2时，则需要判断dp[i+1][j-1]是不是回文。
                if (dp[i][j]) {
                    if (j - i + 1 >= len) {
                        len = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, len);
    }
    /********************
     * 方法2：中心扩展法
     */
    string longestPalindrome2(string s) {
        if (s.empty()) return s;
        int start = 0, end = 0, len = 0;
        for (auto i = 0; i < s.size(); i++) {
            int len1 = expandCenter(s, i, i);  // 比如aba， 当前位置为中心，比如字符b，求得len1 = 3
            int len2 = expandCenter(s, i, i + 1);  // 比如abba 当前两个数字为中心， 比如第一个字符b，求得len2 =4
            len = max(len1, len2);

            if (len > end - start) {  // 寻找回文字符串的最左 最右字符的下标
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
    // 返回当前节点为中心，向两侧扩展的回文字符串的长度
    int expandCenter(string& s, int left, int right) {
        int i = left, j = right;
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        return j - i - 1;
    }
    /*
    Manacher算法
    TODO:
     */
    string longestPalindrome(string s) {
        if (s.empty()) return s;
        return "";
    }
};
// @lc code=end
