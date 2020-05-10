package leetcode;

/**
 * author：baixiaoling
 * date: 2017/12/19
 * <p>
 * description:
 * Follow up for "Search in Rotated Sorted Array": _33题
 * What if duplicates are allowed?
 * Would this affect the run-time complexity? How and why?
 * <p>
 * <p>
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * Write a function to determine if a given target is in the array.
 * The array may contain duplicates.
 */
public class _81_SearchinRotatedSortedArrayII {
    /*
    解题思路：
    二分查找的变体，首先判断mid和target是否相等
   有重复元素 比如 [1,3,1,1,1]
     */
    public boolean search(int[] nums, int target) {
        if (nums == null || nums.length == 0)
            return false;
        int left = 0, right = nums.length - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] < nums[right]) {
                // 从mid到right是有序的
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else if (nums[mid] > nums[right]) {
                // 从left到 mid是有序的
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
//                nums[mid] == nums[right],  有重复元素，字需要向左跳过重复元素即可
                right--;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        _81_SearchinRotatedSortedArrayII object = new _81_SearchinRotatedSortedArrayII();
        int num[] = {4, 5, 6, 7, 2, 1};
        System.out.println(object.search(num, 1));
    }
}
