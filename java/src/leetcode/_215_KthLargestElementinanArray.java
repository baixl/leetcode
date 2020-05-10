package leetcode;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 * author：baixiaoling
 * date: 2018/1/9
 * <p>
 * description:
 * Find the kth largest element in an unsorted array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 * <p>
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * <p>
 * Credits:
 * Special thanks to @mithmatt for adding this problem and creating all test cases.
 * 解题思路：
 * topk问题
 * 1 方法1 使用优先级队列，小顶堆，优先弹出较小元素，java的 PriorityQueue默认是小顶堆（当需要使用大顶堆时，可以自定义 operator函数）
 * 2 快速排序中的partition方法
 */
public class _215_KthLargestElementinanArray {
    /*
    使用优先级队列
     */
    public int findKthLargest(int[] nums, int k) {
        if (nums == null || nums.length == 0 || k <= 0) return 0;
        Queue<Integer> queue = new PriorityQueue<>();
        queue.offer(nums[0]);
        for (int i = 1; i < nums.length; i++) {
            if (queue.size() < k) {
                queue.offer(nums[i]);
            } else {
                int value = queue.peek();
                if (nums[i] > value) {
                    queue.poll();
                    queue.offer(nums[i]);
                }
//                queue.poll();
//                queue.offer(nums[i]);
            }
        }
        return queue.peek();
    }

    /*
    使用快排分区方法，
    快排部分使用左大右小排序
     */
    public int findKthLargest2(int[] nums, int k) {
        if (nums == null || nums.length == 0 || k <= 0) return 0;
        int left = 0, right = nums.length - 1;
        while (true) {
            int postion = partition(nums, left, right);
            if (postion == k - 1) {
                return nums[postion];
            } else if (postion > k - 1) {
                right = postion - 1;
            } else {
                left = postion + 1;
            }
        }

    }

    private int partition(int[] nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1;
        int r = right;

        while (l <= r) {
            if (nums[l] >= pivot) {
                l++;
            } else if (nums[r] <= pivot) {
                r--;
            } else {
                swap(nums, l, r);
                l++;
                r--;
            }
        }
        swap(nums, left, r);
        return r;
    }

    private void swap(int[] num, int i, int j) {
        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }

    public static void main(String[] args) {
        _215_KthLargestElementinanArray object = new _215_KthLargestElementinanArray();
        int[] nums = {3, 2, 1, 5, 2, 4};
        System.out.println(object.findKthLargest2(nums, 2));
    }
}
