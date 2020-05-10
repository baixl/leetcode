package leetcode;

/**
 * author：baixiaoling
 * date: 2018/1/18
 * <p>
 * description:
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * For example,
 * <p>
 * Consider the following matrix:
 * <p>
 * [
 * [1,   4,  7, 11, 15],
 * [2,   5,  8, 12, 19],
 * [3,   6,  9, 16, 22],
 * [10, 13, 14, 17, 24],
 * [18, 21, 23, 26, 30]
 * ]
 * Given target = 5, return true.
 * <p>
 * Given target = 20, return false.
 *
 * 类似的 第74题，Search2DMatrix
 */
public class _240_Searcha2DMatrixII {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0) return false;
        int m = 0;
        int n = matrix[0].length - 1;

        while (m <= matrix.length - 1 && n >= 0) {
            int current = matrix[m][n];
            if (target == current) {
                return true;
            } else if (current > target) {
                n--;
            } else {
                m++;
            }
        }
        return false;
    }


}
