package leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * author：baixiaoling
 * date: 2018/1/11
 * <p>
 * description:
 * Given a matrix of m x n elements (m rows, n columns),
 * return all elements of the matrix in spiral order.
 * For example,
 * Given the following matrix:
 * <p>
 * [
 * [ 1, 2, 3 ],
 * [ 4, 5, 6 ],
 * [ 7, 8, 9 ]
 * ]
 * You should return [1,2,3,6,9,8,7,4,5].
 * 剑指offer 20题
 * 注意边界条件：
 * 5x5矩阵：最后一圈结束只有一个节点，该点下标[2,2]
 * 6x6矩阵：最后一圈是一个2x2的矩阵，左上角下标[2,2]
 * <p>
 * 这两种情况都满足  columns> start*2 row>start*2
 * 上述就是结束条件
 * <p>
 * 然后就是打印每一圈，分别分成：从左到右 从上到下，从右到左，从下到上 四个for循环
 */
public class _54_SpiralMatrix {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) return result;
        int row = matrix.length; // 行
        int column = matrix[0].length; // 列
        int start = 0;
        // 每次打印一圈为一次循环，循环结束条件是：
        while (column > start * 2 && row > start * 2) {
            spiral(matrix, row, column, start, result);
            start++;
        }
        return result;
    }

    private void spiral(int[][] matrix, int row, int column, int start, List<Integer> result) {
        int endX = column - 1 - start;
        int endY = row - 1 - start;

        // 从左至右
        for (int i = start; i <= endX; i++) {
            result.add(matrix[start][i]);
        }
        //从上向下
        if (start < endY) {
            for (int i = start + 1; i <= endY; i++) {
                result.add(matrix[i][endX]);
            }
        }
        // 从右至左
        if (start < endX && start < endY) {
            for (int i = endX - 1; i >= start; i--) {
                result.add(matrix[endY][i]);
            }
        }
        //从下至上
        if (start < endX && start < endY - 1) {
            for (int i = endY - 1; i >= start + 1; i--) {
                result.add(matrix[i][start]);
            }
        }
    }

    public static void main(String[] args) {
        _54_SpiralMatrix object = new _54_SpiralMatrix();
        int[][] matrix = {{1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}};
        System.out.println(object.spiralOrder(matrix));
    }

}