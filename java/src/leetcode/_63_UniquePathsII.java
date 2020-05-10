package leetcode;

/**
 * author：baixiaoling
 * date: 2018/1/2
 * <p>
 * Follow up for "Unique Paths":
 * <p>
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * The total number of unique paths is 2.
 * Note: m and n will be at most 100.
 * <p>
 * 解题思路：
 * 和62题的UniquePath不同的事，这里会存在障碍点，解题思路类是，也是采用动态规划。
 * <p>
 * 需要注意的是：
 * 1  第1行和第1列如果出现障碍点，则障碍点后面的值都应该初始化为0，因为已经走不到了
 * 2 动态规划过程中，dp[i][j] = dp[i-1][j] + dp[i][j-1]的条件任然成立，只是当遇到障碍点时，规划数组中对应的值应该设置为0
 */
public class _63_UniquePathsII {

    /*
    动态规划
     */
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if (obstacleGrid == null || obstacleGrid[0] == null) return 0;
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        if (m == 0 || n == 0 || obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;

        int[][] dp = new int[m][n];

        // 初始化第1行和第1列
        dp[0][0] = 1;
        for (int i = 1; i < m; i++) { // 第1列
            if (obstacleGrid[i][0] == 1) {
                dp[i][0] = 0;
            } else {
                dp[i][0] = dp[i - 1][0];
            }

        }
        for (int i = 1; i < n; i++) { // 第1列
            if (obstacleGrid[0][i] == 1) {
                dp[0][i] = 0;
            } else {
                dp[0][i] = dp[0][i - 1];
            }

        }


        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }

            }
        }
        return dp[m - 1][n - 1];
    }
}
