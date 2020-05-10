/*
* [200] 岛屿数量
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，
并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
示例 1:
输入:
11110
11010
11000
00000
输出: 1
示例 2:
输入:
11000
11000
00100
00011

输出: 3
 */
class Solution {
   public:
	// DFS
	// 每遇到1个1，则依次向4个方向扩展，将相连的1 设置为0， 直到没有连续的1为止
	// 岛屿数量：多有的搜索数量
	void set_sero(vector<vector<char>>& grid, int row, int j) {
		int m = grid.size();
		if (m <= 0) {
			return;
		}
		int n = grid[0].size();
		if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
			return;
		}
		grid[i][j] = '0';
		set_sero(grid, i + 1, j);
		set_sero(grid, i - 1, j);
		set_sero(grid, i, j + 1);
		set_sero(grid, i, j - 1);
	}
	int numIslands(vector<vector<char>>& grid) {
		int row = grid.size();
		if (row <= 0) {
			return 0;
		}
		int column = grid[0].size();
		if (column <= 0) {
			return 0;
		}
		int sum = 0;
		for (auto i = 0; i < row; i++) {
			for (auto j = 0; j < column; j++) {
				if (grid[i][j] == '1') {
					sum += 1;
				}
				set_sero(grid, i, j);
			}
		}
		return sum;
	}
};
