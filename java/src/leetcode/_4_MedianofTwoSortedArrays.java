package leetcode;

import java.util.ArrayList;

/**
 * author：baixiaoling
 * date: 2017/12/9
 * <p>
 * description:https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 */
public class _4_MedianofTwoSortedArrays {
    /*
        转换为求第k大元素： 合并后的中位数即第k（len/2）小元素
        解法1： 插入排序，选择第k大的元素（需要判断集合的长度为偶数还是基数）
        实际上不需要使用一个完整的插入排序，只需要在插入的时候找到第k小元素就行
     */
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len = nums1.length + nums2.length;
        ArrayList<Integer> list = new ArrayList<>();
        int index1 = 0, index2 = 0;
        // todo 这里可以做一步优化，不需要完全插入排序 ，只需要判断插入时下标达到 len/2 即可
        while (index1 < nums1.length && index2 < nums2.length) {
            if (nums1[index1] < nums2[index2]) {
                list.add(nums1[index1]);
                index1++;
            } else if (nums1[index1] > nums2[index2]) {
                list.add(nums2[index2]);
                index2++;
            } else {
                list.add(nums1[index1]);
                list.add(nums2[index2]);
                index1++;
                index2++;
            }
        }
        while (index1 < nums1.length) {
            list.add(nums1[index1]);
            index1++;
        }
        while (index2 < nums2.length) {
            list.add(nums2[index2]);
            index2++;
        }
        System.out.println(list);
        if (len % 2 == 1) {
            return (double) list.get(len / 2);
        } else {
            return (double) (list.get(len / 2) + list.get(len / 2 - 1)) / 2;
        }
    }

    /*
        方法2：还是转化为求第k小问题，但是每次比较num1 和num2中间位置的元素
        然后根据比较结果，递归进行计算
        c++:http://blog.csdn.net/yutianzuijin/article/details/11499917
        java:http://www.cnblogs.com/lichen782/p/leetcode_Median_of_Two_Sorted_Arrays.html
        //todo 这个代码细节需要理解
     */
    public static double findMedianSortedArrays2(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        int l = (m + n + 1) / 2;
        int r = (m + n + 2) / 2;
        return (getKth(nums1, 0, nums2, 0, l) + getKth(nums1, 0, nums2, 0, r)) / 2.0;
    }

    // 求第k小的数字
    public static double getKth(int[] nums1, int start1, int[] nums2, int start2, int k) {
        if (start1 > nums1.length - 1) return nums2[start2 + k - 1];
        if (start2 > nums2.length - 1) return nums1[start1 + k - 1];
        if (k == 1) return Math.min(nums1[start1], nums2[start2]);

        int mid1 = Integer.MAX_VALUE, mid2 = Integer.MAX_VALUE;
        if (start1 + k / 2 - 1 <= nums1.length - 1) mid1 = nums1[start1 + k / 2 - 1];
        if (start2 + k / 2 - 1 <= nums2.length - 1) mid2 = nums2[start2 + k / 2 - 1];
        if (mid1 < mid2) {
            return getKth(nums1, start1 + k / 2, nums2, start2, k - k / 2);
        } else {
            return getKth(nums1, start1, nums2, start2 + k / 2, k - k / 2);
        }
    }

    public static void main(String[] args) {
        int[] num1 = {1, 3};
        int[] num2 = {2, 4};
        System.out.println(findMedianSortedArrays2(num1, num2));
    }

}
