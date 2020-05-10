package leetcode;

import java.util.HashMap;
import java.util.Map;

/**
 * author：baixiaoling
 * date: 2018/1/20
 * <p>
 * description:
 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
 * prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
 * find the duplicate one.
 * <p>
 * Note:
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated more than once.
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 * <p>
 * 思路：
 * https://segmentfault.com/a/1190000003817671
 */
public class _287_FindtheDuplicateNumber {
    /*
    使用hash存放数组，这种方式也能ac ，但是明显空间不满足要求
     */
    public int findDuplicate(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                return nums[i];
            } else {
                map.put(nums[i], 1);
            }
        }

        return -1;
    }

    public int findDuplicateByBin(int[] nums) {
        int min = 0, max = nums.length - 1;
        while (min <= max) {
            // 找到中间那个数
            int mid = min + (max - min) / 2;
            int cnt = 0;
            // 计算总数组中有多少个数小于等于中间数
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] <= mid) {
                    cnt++;
                }
            }
            // 如果小于等于中间数的数量大于中间数，说明前半部分必有重复
            if (cnt > mid) {
                max = mid - 1;
                // 否则后半部分必有重复
            } else {
                min = mid + 1;
            }
        }
        return min;
    }
}
