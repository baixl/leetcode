package leetcode;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * author：baixiaoling
 * date: 2018/1/3
 * <p>
 * description:
 * Given a set of distinct integers, nums, return all possible subsets (the power set).
 * <p>
 * Note: The solution set must not contain duplicate subsets.
 * <p>
 * For example,
 * If nums = [1,2,3], a solution is:
 * <p>
 * [
 * [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 解题思路： 非递归版本
 * 从头开始遍历 数组，
 * 1 一次插入 result
 * 2 每遇到一个新的元素。将该元素插入result中所以列表的末尾，并作为新的list插入result中
 */
public class _78_Subsets {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if (nums == null || nums.length == 0) {
            result.add(new ArrayList<>());
        }

        result.add(new ArrayList<>());
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            int size = result.size();
            for (int j = 0; j < size; j++) {
                List<Integer> item = new ArrayList<>(result.get(j));
                item.add(nums[i]);
                result.add(item);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        _78_Subsets object = new _78_Subsets();
        int[] nums = {-1, 1, 2};
        System.out.println(object.subsets(nums));
    }
}
