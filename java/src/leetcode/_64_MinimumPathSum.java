package leetcode;

/**
 * author：baixiaoling
 * date: 2018/1/2
 * <p>
 * description:
 * Given a m x n grid filled with non-negative numbers,
 * find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 * <p>
 * Note: You can only move either down or right at any point in time.
 * <p>
 * Example 1:
 * [[1,3,1],
 * [1,5,1],
 * [4,2,1]]
 * Given the above grid map, return 7. Because the path 1→3→1→1→1 minimizes the sum.
 * <p>
 * 动态规划： 和  Unique Path类似
 * <p>
 * dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
 */
public class _64_MinimumPathSum {
    public int minPathSum(int[][] grid) {
        if (grid == null || grid[0].length == 0) return 0;

        int m = grid.length; // 行数
        int n = grid[0].length; // 列数
        int[][] dp = new int[m][n];
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {

                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }

    public static void main(String[] args) {
        _64_MinimumPathSum object = new _64_MinimumPathSum();

        int[][] nums = {
                {1, 2, 5},
                {3, 2, 1},
        };
        System.out.println(object.minPathSum(nums));

    }
}
