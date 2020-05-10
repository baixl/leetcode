package leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * author：baixiaoling
 * date: 2017/12/13
 * <p>
 * description: https://leetcode.com/problems/3sum/description/
 * 对 TwoSum的扩展
 */
public class _15_3Sum {
    /*
    找到 a+b+c =0
     */
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> lists = new ArrayList<List<Integer>>();
        if (nums == null || nums.length < 3) {
            return lists;
        }
        // 先排序，不排序不好处理重复元素
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            ArrayList<Integer> list = new ArrayList<>();
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int target = 0 - nums[i];
            int l = i + 1, r = nums.length - 1;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    list.add(nums[i]);
                    list.add(nums[l]);
                    list.add(nums[r]);
                    lists.add(list);
                    list = new ArrayList<>();
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                } else if (nums[l] + nums[r] > target) {
                    r--;
                } else {
                    l++;
                }
            }

        }
        return lists;
    }

    public static void main(String[] args) {
        _15_3Sum object = new _15_3Sum();
        int[] nums = {-2, 0, 1, 1, 2};
        System.out.println(object.threeSum(nums));
    }
}
