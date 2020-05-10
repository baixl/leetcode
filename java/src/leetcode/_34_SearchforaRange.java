package leetcode;

import java.util.Arrays;

/**
 * author：baixiaoling
 * date: 2017/12/19
 * <p>
 * description:
 * Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */
public class _34_SearchforaRange {
    /*
    时间复杂度为O(log n)，则不能用顺序遍历
    使用三次二分查找：
    1 找到一个和目标值相等的元素
    2 从该位置左右移动，还是使用二分查找
     */
    public int[] searchRange(int[] nums, int target) {
        int[] ret = {-1, -1};
        if (nums == null || nums.length == 0)
            return ret;

        int left = 0, right = nums.length - 1;
        // 找到第一个等于目标值的元素
        int mid = -1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                ret[0] = mid;
                ret[1] = mid;
                break;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (nums[mid] != target) {
            //没找到元素
            return ret;
        }
        int newLeft = mid;
        int newRight = nums.length - 1;
        while (newLeft <= newRight) {
            int newMid = (newLeft + newRight) / 2;
            if (nums[newMid] == target) {
                newLeft = newMid + 1;
            } else {
                newRight = newMid - 1;
            }
        }
        ret[1] = newRight;

        newLeft = 0;
        newRight = mid;
        while (newLeft <= newRight) {
            int newMid = (newLeft + newRight) / 2;
            if (nums[newMid] == target) {
                newRight = newMid - 1;
            } else {
                newLeft = newMid + 1;
            }
        }
        ret[0] = newLeft;
        return ret;
    }

    public static void main(String[] args) {
        _34_SearchforaRange object = new _34_SearchforaRange();
        int num[] = {5, 7, 7, 8, 8, 10};
        System.out.println(Arrays.toString(object.searchRange(num, 8)));
    }

}
