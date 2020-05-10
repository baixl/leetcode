package leetcode;

/**
 * author：baixiaoling
 * date: 2018/1/2
 * <p>
 * description:
 * Given two words word1 and word2, find the minimum number of steps required
 * to convert word1 to word2. (each operation is counted as 1 step.)
 * <p>
 * You have the following 3 operations permitted on a word:
 * <p>
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 * 求两个字符串的最小编辑距离：
 * http://www.dreamxu.com/books/dsa/dp/edit-distance.html
 * 解题思路：
 * 动态规划：
 * 用分治的思想解决比较简单，将复杂的问题分解成相似的子问题
 * <p>
 * 假设字符串 a, 共 m 位，从 a[1] 到 a[m]
 * 字符串 b, 共 m 位，从 b[1] 到 b[n]
 * d[i][j] 表示字符串 a[1]-a[i] 转换为 b[1]-b[i] 的编辑距离
 * <p>
 * 那么有如下递归规律（a[i] 和 b[j] 分别是字符串 a 和 b 的最后一位）：
 * <p>
 * 1 当 a[i] 等于 b[j] 时，d[i][j] = d[i-1][j-1],
 * <p>
 * 2 当 a[i] 不等于 b[j] 时，d[i][j] 等于如下 3 项的最小值：
 * <p>
 * 2.1 d[i-1][j] + 1（删除 a[i]），
 * 2.2 d[i][j-1] + 1（插入 b[j])，
 * 2.3 d[i-1][j-1] + 1（将 a[i] 替换为 b[j]），
 * 递归边界：
 * <p>
 * a[i][0] = i, b 字符串为空，表示将 a[1]-a[i] 全部删除，所以编辑距离为 i
 * a[0][j] = j, a 字符串为空，表示 a 插入 b[1]-b[j]，所以编辑距离为 j
 */
public class _72_EditDistance {
    public int minDistance(String word1, String word2) {
        if (word1 == null && word2 == null) return 0;
        if (word1 == null || word1.length() == 0) return word2.length();
        if (word2 == null || word2.length() == 0) return word1.length();

        int m = word1.length();
        int n = word2.length();
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 0; i < m + 1; i++) {
            dp[i][0] = i;
        }
        for (int i = 0; i < n + 1; i++) {
            dp[0][i] = i;
        }

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.min(dp[i - 1][j], Math.min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                }
            }
        }

        return dp[m][n];
    }
}
