package leetcode;

/**
 * author：baixiaoling
 * date: 2018/1/2
 * <p>
 * description:
 * Given a string S and a string T, count the number of distinct subsequences of S which equals T.
 * A subsequence of a string is a new string which is formed from the original string by deleting some (can be none)
 * of the characters without disturbing the relative positions of the remaining characters.
 * (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 * <p>
 * Return 3.
 * https://segmentfault.com/a/1190000003481216
 * 解题思路：
 * 题意，求字符串S中有多少个子序列和T相等。子序列不要求连续
 * 这是一个典型的动态规划题题目。关键是要求动态规划中的状态转移公式
 * 1 当s为空时，返回0
 * 2 当t为空串时，返回1 ，因为空串是另外一个字符串的子串
 * 3 这里关键是比较 s[0.....i] 与 t[0.....j],即比较两个子串的最后一个字符 s[i] t[j]
 * 即先遍历s，一次比较t的最后一个字符是否和当前的母串最后一个字符相等
 * s[i]!=t[j]:  即最后一个字符不相等，则至少会与上一个比较结果 dp[j][i-1]相等
 * 当s[i] == t[j]: 即最后一个字符相等，说明新加入的字符会增加新的可能性。增加可能性大小为两个子串都去掉最后一个字符的结过即
 * 此时，dp(i)(j) = dp(j)(i-1) + dp(i-1)(j-1)
 */
public class _115_DistinctSubsequences {
    public int numDistinct(String s, String t) {
        if (s == null) return 0;
        if (t == null || t.length() == 0) return 1;
        int m = t.length();
        int n = s.length();
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1; // 因为 t为空串
        }
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (t.charAt(i - 1) != s.charAt(j - 1)) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }

    public static void main(String[] args) {
        _115_DistinctSubsequences object = new _115_DistinctSubsequences();
        System.out.println(object.numDistinct("rabbbit", "rabbit"));
    }
}