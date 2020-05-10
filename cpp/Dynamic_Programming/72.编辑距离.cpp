/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 *
 * https://leetcode-cn.com/problems/edit-distance/description/
 *
 * Hard (54.88%)
 * 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
 * 你可以对一个单词进行如下三种操作：
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 *
 * 示例 1:
 * 输入: word1 = "horse", word2 = "ros"
 * 输出: 3
 * 解释:
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 * 示例 2:
 *
 * 输入: word1 = "intention", word2 = "execution"
 * 输出: 5
 * 解释:
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 */

// @lc code=start
class Solution {
   public:
    /*
    求两个字符串的编辑距离：
    给定两个字符串word1 和word2，计算出将word1转换成word2的最小操作次数
    总共可以使用三种操作方法：
    * 插入一个字符
    * 删除一个字符
    * 替换一个字符
    
    这是一道典型的动态规划题目。
    假设字符串a共有m位， a[1]…a[m]
    假设字符串b共有n位， b[1]…a[n]
    dp[i][j]表示字符串a[1]...a[i]转换为b[1]...b[j]的编辑距离。
    那么有如下递归规律:
    1. 当a[i] == b[j]:表示不需要操作，dp[i][j] = dp[i-1][j-1]
    2. 当a[i] != b[j],此时有三种操作方式
        1. dp[i][j] = dp[i-1][j]+1， 插入a[i]
        2. dp[i][j] = dp[i][j-1]+1， 删除b[j]
        3. dp[i][j] = dp[i-1][j-1]+1，替换a[i]为b[j]
            此时 dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1)
    3 边界条件：
    * a[i][0] = i, b 字符串为空，表示将 a[1]-a[i] 全部删除，所以编辑距离为 i
    * a[0][j] = j, a 字符串为空，表示 a 插入 b[1]-b[j]，所以编辑距离为 j

    */
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        if (len1 == 0) return len2;
        if (len2 == 0) return len1;

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, INT_MAX));
        // 第1列， 表示word2是空串，将word1，依次删除即可
        for (auto i = 0; i <= len1; i++) {
            dp[i][0] = i;
        }
        // 第一行，表示word1是空串，依次插入word2的字符即可
        for (auto j = 0; j <= len2; j++) {
            dp[0][j] = j;
        }
        //将word1[0:i]变换成word2[0:j]
        for (auto i = 1; i <= len1; i++) {
            for (auto j = 1; j <= len2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];  // 当前什么都不做
                } else {
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        return dp[len1][len2];
    }
};
// @lc code=end
