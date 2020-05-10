package leetcode;

import java.util.Arrays;

/**
 * author：baixiaoling
 * date: 2017/12/13
 * <p>
 * description:
 */
public class _16_3SumClosest {
    public int threeSumClosest(int[] nums, int target) {
        if (nums == null || nums.length < 3) {
            return 0;
        }
        int sum = nums[0] + nums[1] + nums[2];
        int diff = Math.abs(sum - target);
        Arrays.sort(nums);
        int res = sum;
        for (int i = 0; i < nums.length; i++) {
            int left = i + 1, right = nums.length - 1;
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                int newDiff = Math.abs(sum - target);
                if (newDiff == 0) { // 提前结束
                    return sum;
                }
                if (newDiff < diff) {
                    diff = newDiff;
                    res = sum;
                }
                if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        _16_3SumClosest object = new _16_3SumClosest();
        int[] nums = {1, 1, 1, 0};
        int target = -100;
        System.out.println(object.threeSumClosest(nums, target));
    }
}