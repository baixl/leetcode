package leetcode;

import java.util.Arrays;

/**
 * author：baixiaoling
 * date: 2017/12/19
 * <p>
 * description:
 */
public class _35_SearchInsertPosition {
    public int searchInsert(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int left = 0, right = nums.length - 1;
        int mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    public static void main(String[] args) {
        _35_SearchInsertPosition object = new _35_SearchInsertPosition();
        int num[] = {1, 3, 5, 6};
        System.out.println((object.searchInsert(num, 9)));
    }
}
