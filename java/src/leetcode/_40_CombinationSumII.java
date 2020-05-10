package leetcode;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/**
 * author：baixiaoling
 * date: 2017/12/20
 * <p>
 * description:
 * Given a collection of candidate numbers (C) and a target number (T),
 * find all unique combinations in C where the candidate numbers sums to T.
 * Each number in C may only be used once in the combination.
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
 * A solution set is:
 * [
 * [1, 7],
 * [1, 2, 5],
 * [2, 6],
 * [1, 1, 6]
 * ]
 */
public class _40_CombinationSumII {
    /*
    和第39题类似：
    https://segmentfault.com/a/1190000003743112
    可以参考这里的解题思路：分别介绍了类似的三个题目：Combination Sum ：I II III
    三道题思路差不多都是递归的方式（DFS）

    这种题本质上试DFS，解决办法是递归（深度遍历）
    1 首先进行排序
    2 递归搜索时，先加入，元素，再递归搜索，由于可以使用重复字符，则，下次递归的下标从下一个下标开始
    3 注意相同数字，第一个需要递归，后面的数字就不用再递归了
     */
    List<List<Integer>> ret;

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {

        ret = new LinkedList<>();
        Arrays.sort(candidates);
        List<Integer> temp = new LinkedList<>();
        helper(candidates, target, 0, temp);
        return ret;

    }

    /*
    递归辅助函数
     */
    private void helper(int[] nums, int target, int index, List<Integer> temp) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            List<Integer> one = new LinkedList<>(temp);
            ret.add(one);
        } else {
            // 递归
            for (int i = index; i < nums.length; i++) {
                // 先加入元素，再DFS搜索，递归回来再移除元素
                temp.add(nums[i]);
//                System.out.println("添加后：" + temp);
                helper(nums, target - nums[i], i + 1, temp);
                temp.remove(temp.size() - 1);
//                System.out.println("移除后：" + temp);
//                跳过余下重复元素
                while (i < nums.length - 1 && nums[i] == nums[i + 1]) {
                    ++i;
                }
            }
        }
    }

    public static void main(String[] args) {
        _40_CombinationSumII object = new _40_CombinationSumII();
        int[] nums = {10, 1, 2, 7, 6, 1, 5};
        System.out.println(object.combinationSum2(nums, 8));
    }
}
