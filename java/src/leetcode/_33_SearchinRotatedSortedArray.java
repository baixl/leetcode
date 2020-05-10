package leetcode;

/**
 * author：baixiaoling
 * date: 2017/12/19
 * <p>
 * description:
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * <p>
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * <p>
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * <p>
 * You may assume no duplicate exists in the array.
 */
public class _33_SearchinRotatedSortedArray {
    /*
    解题思路：
    二分查找的变体，首先判断mid和target是否相等
    1 相等，返回下标
    2 mid比nums[right] 小，说明从mid到right是升序的，判断target是否在这个区间
    3 mid比nums[right] 大，说明从left到mid是升序的，判断target是否在这个区间
     */
    public int search(int[] nums, int target) {
        if (nums == null || nums.length == 0)
            return -1;
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < nums[right]) {
                // 从mid到right是有序的
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                // 从left到 mid是有序的
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        _33_SearchinRotatedSortedArray object = new _33_SearchinRotatedSortedArray();
        int num[] = {4, 5, 6, 2, 3};
        System.out.println(object.search(num, 1));
    }
}
