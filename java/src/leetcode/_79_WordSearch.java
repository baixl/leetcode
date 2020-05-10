package leetcode;

/**
 * author：baixiaoling
 * date: 2018/1/4
 * description:
 * Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring.
 * The same letter cell may not be used more than once.
 * <p>
 * For example,
 * Given board =
 * [
 * ['A','B','C','E'],
 * ['S','F','C','S'],
 * ['A','D','E','E']
 * ]
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 * 解题思路：深度搜索
 * https://segmentfault.com/a/1190000003697153
 */
public class _79_WordSearch {
    public boolean exist(char[][] board, String word) {
        if (board == null || board.length == 0 || board[0].length == 0) return false;
        if (word == null || word.length() == 0) return true;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                boolean existed = dfs(i, j, board, word, 0);
                if (existed) return true;
            }
        }
        return false;
    }

    private boolean dfs(int i, int j, char[][] board, String word, int index) {
        if (index >= word.length()) return true;
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] != word.charAt(index))
            return false;
        char temp = board[i][j];
        board[i][j] = '#'; // 避免重复访问
        boolean result = dfs(i - 1, j, board, word, index + 1)
                || dfs(i + 1, j, board, word, index + 1)
                || dfs(i, j - 1, board, word, index + 1)
                || dfs(i, j + 1, board, word, index + 1);
        board[i][j] = temp; // 恢复现场
        return result;
    }

    public static void main(String[] args) {
        _79_WordSearch object = new _79_WordSearch();
        char[][] board = {
                {'A', 'B', 'C', 'E'},
                {'S', 'F', 'C', 'S'},
                {'A', 'D', 'E', 'E'}
        };
        System.out.println(object.exist(board, "ABCCED"));
    }
}
