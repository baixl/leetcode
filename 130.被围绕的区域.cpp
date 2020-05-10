/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 *
 * https://leetcode-cn.com/problems/surrounded-regions/description/
 *
 * Medium (39.74%)
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 *
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 *
 * 示例:
 *
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 *
 * 运行你的函数后，矩阵变为：
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 *
 * 解释:
 *
 * 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。
 * 任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 *
 */

// @lc code=start
class Solution {
   public:
    /*************************************************
     其实不需要 visited 矩阵， 只需要在遍历时改变原来的值即可
     *************************************************/
      void solve(vector<vector<char>>& board) {
        int row = board.size();
        if (row == 0) return;
        int col = board[0].size();
        for (auto i = 0; i < row; i++) {
            for (auto j = 0; j < col; j++) {
                if (i ==0 || i == row -1 || j==0 || j== col-1) {
                    dfs_new(board,i, j);
                } else {
                    continue;
                }
            }
        }
        for (auto i = 0; i < row; i++) {
            for (auto j = 0; j < col; j++) {
                if (board[i][j] == 'S') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';             
                }
            }
        }
        return;
    }

    void dfs_new(vector<vector<char>>& board,  int i, int j) {
        int row = board.size(), col = board[0].size();
        if(i<0|| i>= row || j <0|| j>= col) return;
        if ( board[i][j] != 'O') return;
        board[i][j] = 'S';
        dfs_new(board, i+1, j);
        dfs_new(board, i-1, j);
        dfs_new(board, i, j+1);
        dfs_new(board, i, j-1);
         
    }


    /*************************************************
    方法： DFS：
    1、设置和board大小相同的矩阵 visited[i][j] 开始每个位置都是0，
    2、从任意边界上的一个o开始沿着上下左右4个方向深度遍历，遍历过程中遇到x就返回，
    3、遍历过程中，每个visited[i][j] 设置为1， 表示该位置的数字是o并且不需要更换为x
    4、遍历visited[i][j] 将每个 为0的位置，设置为x
    */
    void solve2(vector<vector<char>>& board) {
        int row = board.size();
        if (row == 0) return;
        int col = board[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        for (auto i = 0; i < row; i++) {
            for (auto j = 0; j < col; j++) {
                if (i ==0 || i == row -1 || j==0 || j== col-1) {
                    dfs(board, visited, i, j);
                } else {
                    continue;
                }
            }
        }
        for (auto i = 0; i < row; i++) {
            for (auto j = 0; j < col; j++) {
                if (visited[i][j] == 0 && board[i][j] != 'X') {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }

    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j) {
        int row = board.size(), col = board[0].size();
        if(i<0|| i>= row || j <0|| j>= col) return;
        if (visited[i][j] == 1 || board[i][j] == 'X') return;
        visited[i][j] = 1;
        dfs(board, visited, i+1, j);
        dfs(board, visited, i-1, j);
        dfs(board, visited, i, j+1);
        dfs(board, visited, i, j-1);
         
    }
};
// @lc code=end
