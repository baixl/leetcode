package leetcode;

import java.util.Arrays;

/**
 * author：baixiaoling
 * date: 2017/12/25
 * <p>
 * description:
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to m + n)
 * to hold additional elements from nums2.
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 */
public class _88_MergeSortedArray {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        // 从后往前遍历两个数组，一次填入nums1
//        if (nums2 == null || nums2.length == 0) return;
//        if (nums1 == null || nums1.length == 0 || m == 0) {
//            nums1 = nums2;
//            return;
//        }
        int mnindex = m + n - 1;
        int index1 = m - 1;
        int index2 = n - 1;
        while (index1 >= 0 && index2 >= 0) {
            nums1[mnindex--] = nums1[index1] >= nums2[index2] ? nums1[index1--] : nums2[index2--];
        }

        while (index2 >= 0) {
            nums1[mnindex--] = nums2[index2--];
        }
        System.out.println(Arrays.toString(nums1));
    }

    public static void main(String[] args) {
        _88_MergeSortedArray obejct = new _88_MergeSortedArray();
        int[] A = {1, 0};
        int[] B = {2};
        obejct.merge(A, 1, B, 1);
    }
}
