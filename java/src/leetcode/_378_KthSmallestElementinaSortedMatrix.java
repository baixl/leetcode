package leetcode;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 * author：baixiaoling
 * date: 2018/1/15
 * <p>
 * description:
 * 解题思路：
 * Given a n x n matrix where each of the rows and columns are sorted in ascending order,
 * find the kth smallest element in the matrix.
 * <p>
 * Note that it is the kth smallest element in the sorted order, not the kth distinct element.
 * <p>
 * Example:
 * <p>
 * matrix = [
 * [ 1,  5,  9],
 * [10, 11, 13],
 * [12, 13, 15]
 * ],
 * k = 8,
 * <p>
 * return 13.
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ n2.
 * <p>
 * 解题思路：
 * 1 使用堆排序，大顶堆
 * 2 二分查找
 */
public class _378_KthSmallestElementinaSortedMatrix {
    /*
    使用堆排序的思路
    使用一个大顶堆，
     */
    public int kthSmallest(int[][] matrix, int k) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0 || k <= 0) return 0;
        Queue<Integer> queue = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });
//        queue.offer(matrix[0][0]);
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (queue.size() < k) {
                    queue.offer(matrix[i][j]);
                    System.out.println(queue);
                } else {
                    int value = queue.peek();
                    if (matrix[i][j] < value) {
                        queue.poll();
                        queue.offer(matrix[i][j]);
                    }
                }
            }

        }
        return queue.peek();
    }

    public static void main(String[] args) {
        _378_KthSmallestElementinaSortedMatrix object = new _378_KthSmallestElementinaSortedMatrix();
        int[][] matrix = {{1, 5, 9},
                {10, 11, 13},
                {12, 13, 15}};
        System.out.println(object.kthSmallest(matrix, 8));
    }

}
