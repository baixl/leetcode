package leetcode;

/**
 * author：baixiaoling
 * date: 2018/1/10
 * <p>
 * description:
 * 求两个字符串的最长公共子序列：
 * <p>
 * 子序列：不要求连续
 * 最长公共子序列不同于最长子串，LCS不要求连续，其解法是通过动态规划实现：
 * 动态规划：dp[i][j]表示s1上是s[i]结尾和s2上s[j]结尾的子串的最长公共子串，
 * 最长公共子串是连续的 其状态转移方程是：：dp[i, j] = (s1[i] == s2[j] ? dp[i-1, j-1] + 1 : 0)
 * 而最长公共子序列不要求连续：
 * 当当前位置s[i] ==s[j]  则  dp[i,j] = dp[i-1,j-1]+1;
 * 当当前位置s[i] 1=s[j]  则  dp[i,j] = max(dp[i,j-1], dp[j-1, j]);
 */
public class _LongestCommonSubsequence {
    public int longestCommonSubsequence(String s1, String s2) {
        if (s1 == null || s1.isEmpty() || s2 == null || s2.isEmpty()) return 0;
        int length1 = s1.length();
        int length2 = s2.length();
        int[][] dp = new int[length1 + 1][length2 + 1];
        for (int i = 1; i < length1 + 1; i++) {
            for (int j = 1; j < length2 + 1; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }

        }
        return dp[length1][length2];
    }

    public static void main(String[] args) {
        _LongestCommonSubsequence object = new _LongestCommonSubsequence();
        System.out.println(object.longestCommonSubsequence("22", "22"));
    }
}
