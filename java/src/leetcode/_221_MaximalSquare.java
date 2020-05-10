package leetcode;

/**
 * author：baixiaoling
 * date: 2018/1/3
 * <p>
 * description:
 * Given a 2D binary matrix filled with 0's and 1's,
 * find the largest square containing only 1's and return its area.
 * <p>
 * For example, given the following matrix:
 * <p>
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * Return 4.
 * Credits:
 * Special thanks to @Freezen for adding this problem and creating all test cases.
 * 解题思路:动态规划 关键是找到某个正方形（右下角）的最大正方形边长
 * 假设某个右下角的点为正方形的右下角，则其左、左上、上应该都是正方形，否则右下角就只有自己构成正方形。
 * 该点为右下角的正方形的最大边长，最多比它的上方，左方和左上方为右下角的正方形的边长多1，
 * 最好的情况是是它的上方，左方和左上方为右下角的正方形的大小都一样的，这样加上该点就可以构成一个更大的正方形。
 * 但如果它的上方，左方和左上方为右下角的正方形的大小不一样，合起来就会缺了某个角落，
 * 这时候只能取那三个正方形中最小的正方形的边长加1了。假设dpi表示以i,j为右下角的正方形的最大边长，则有
 * <p>
 * dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
 */
public class _221_MaximalSquare {
    public int maximalSquare(char[][] matrix) {
        if (matrix == null || matrix.length == 0) return 0;
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] dp = new int[m][n]; // 存放每个点（为正方形右下角）对应的正方形的半径

        int max = Integer.MIN_VALUE;
        // 第1列
        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] - '0';
            max = Math.max(dp[i][0], max);
        }
        // 第1行
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i] - '0';
            max = Math.max(dp[0][i], max);
        }
        // 遍历二维数组
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
                max = Math.max(dp[i][j], max);

            }
        }
        return max * max;
    }

    public static void main(String[] args) {
        _221_MaximalSquare object = new _221_MaximalSquare();
        char[][] matrix = {
                {'1', '0', '1', '0', '0'},
                {'1', '0', '1', '1', '1'},
                {'1', '1', '1', '1', '1'},
                {'1', '0', '0', '1', '0'}};
        System.out.println(object.maximalSquare(matrix));
    }
}
