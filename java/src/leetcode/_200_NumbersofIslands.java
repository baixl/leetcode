package leetcode;

/**
 * author：baixiaoling
 * date: 2018/1/18
 * <p>
 * description:
 * Given a 2d grid map of '1's (land) and '0's (water),
 * count the number of islands. An island is surrounded by water
 * and is formed by connecting adjacent lands horizontally or vertically.
 * You may assume all four edges of the grid are all surrounded by water.
 * <p>
 * Example 1:
 * <p>
 * 11110
 * 11010
 * 11000
 * 00000
 * Answer: 1
 * <p>
 * Example 2:
 * <p>
 * 11000
 * 11000
 * 00100
 * 00011
 * Answer: 3
 * <p>
 * Credits:
 * Special thanks to @mithmatt for adding this problem and creating all test cases.
 * 解题思路：
 * DFS和递归
 * 从左上角开始遍历，没遇到一个1，就将其上下左右（递归）相连的1标记为0，
 * 则遍历过程中，遇到的1的个数就是独立的岛屿的个数
 */
public class _200_NumbersofIslands {
    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) return 0;
        int result = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == '1') {
                    search(grid, i, j);
                    result++;
                }
            }
        }
        return result;
    }

    private void search(char[][] grid, int i, int j) {
        grid[i][j] = '0';
        // 上一行
        if (i > 0 && grid[i - 1][j] == '1') search(grid, i - 1, j);
        //下一行
        if (i < grid.length - 1 && grid[i + 1][j] == '1') search(grid, i + 1, j);
        //右一列
        if (j > 0 && grid[i][j - 1] == '1') search(grid, i, j - 1);
        // 左一列
        if (j < grid[0].length - 1 && grid[i][j + 1] == '1') search(grid, i, j + 1);
    }
}
