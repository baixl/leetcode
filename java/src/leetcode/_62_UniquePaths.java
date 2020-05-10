package leetcode;

import java.util.Arrays;

/**
 * author：baixiaoling
 * date: 2018/1/2
 * <p>
 * description:
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time.
 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * How many possible unique paths are there?
 * Above is a 3 x 7 grid. How many possible unique paths are there?
 * Note: m and n will be at most 100.
 * <p>
 * 解题思路：
 * 方法1 ：递归，DFS ： 需要在中间过程去重，不然会超时
 * 方法2：动态规划：机器人只能向下或者向右走，则一个点[i][j] 只能由[i-1][j]或者[i][j-1]。
 * 设path[i][j]为到达点[i][j]的步数，则状态转移方程为：path[i][j] = path[i-1][j] +path[i][j-1]
 */
public class _62_UniquePaths {
    /*
    方法1 ：递归 DFS ，需要缓存中间结果，否则可能超时
     */
    public int uniquePaths(int m, int n) {
        int[][] mat = new int[m + 1][n + 1];
        for (int i = 0; i < m + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                mat[i][j] = 0;
            }
        }
        return dfs(m, n, mat);
    }

    private int dfs(int m, int n, int[][] mat) {
        if (m <= 0 || n <= 0) return 0;
        if (m == 1 || n == 1) return 1;
        return getOrUpdate(m - 1, n, mat) + getOrUpdate(m, n - 1, mat);
    }

    private int getOrUpdate(int x, int y, int[][] mat) {
        if (mat[x][y] > 0) return mat[x][y];
        else {
            mat[x][y] = dfs(x, y, mat);
            return mat[x][y];
        }
    }

    /*
    动态规划
     */
    public int uniquePaths2(int m, int n) {
        if (m <= 0 || n <= 0) return 0;
        if (m == 1 || n == 1) return 1;
        int[][] dp = new int[m][n]; // 保存中间结果
        for (int i = 0; i < m; i++) { // 第1列
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++) { // 第1行
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

}
