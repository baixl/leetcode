package leetcode;

/**
 * author：baixiaoling
 * date: 2017/12/26
 * <p>
 * description:
 */
public class _74_Search2DMatrix {
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

    public static void main(String[] args) {
        _74_Search2DMatrix object = new _74_Search2DMatrix();
        int[][] matrix = {{1}};

        System.out.println(object.searchMatrix(matrix, 2));
    }
}
