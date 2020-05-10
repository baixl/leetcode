package leetcode;

import java.util.LinkedList;
import java.util.Queue;

/**
 * author：baixiaoling
 * date: 2017/12/31
 * <p>
 * description:
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
 * <p>
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 * <p>
 * For example,
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * After running your function, the board should be:
 * <p>
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 解题思路：
 * 从上下左右 四面往里走凡事能遇到'O'，都是与边界相通的，都需要保留
 * 参考：http://blog.csdn.net/linhuanmars/article/details/22904855
 */
public class _130_SurroundedRegions {
    public void solve(char[][] board) {
        if (board == null || board.length <= 1 || board[0].length <= 1)
            return;
        for (int i = 0; i < board[0].length; i++) {
            fill(board, 0, i);
            fill(board, board.length - 1, i);
        }
        for (int i = 0; i < board.length; i++) {
            fill(board, i, 0);
            fill(board, i, board[0].length - 1);
        }

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }

    // DFS
    private void fill(char[][] board, int i, int j) {
        if (board[i][j] != 'O')
            return;
        board[i][j] = '#';
        Queue<Integer> queue = new LinkedList<>(); // 存放节点的位置坐标
        int code = i * (board[0].length) + j;
        queue.offer(code);
        while (!queue.isEmpty()) {
            code = queue.poll();
            int row = code / board[0].length;
            int col = code % board[0].length;
            if (row > 0 && board[row - 1][col] == 'O') {
                queue.offer((row - 1) * board[0].length + col);
                board[row - 1][col] = '#';
            }
            if (row < board.length - 1 && board[row + 1][col] == 'O') {
                queue.offer((row + 1) * board[0].length + col);
                board[row + 1][col] = '#';
            }
            if (col > 0 && board[row][col - 1] == 'O') {
                queue.offer(row * board[0].length + col - 1);
                board[row][col - 1] = '#';
            }
            if (col < board[0].length - 1 && board[row][col + 1] == 'O') {
                queue.offer(row * board[0].length + col + 1);
                board[row][col + 1] = '#';
            }
        }
    }
}
