package leetcode;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/**
 * author：baixiaoling
 * date: 2017/12/20
 * <p>
 * description:
 * Given a set of candidate numbers (C) (without duplicates) and a target number (T),
 * find all unique combinations in C where the candidate numbers sums to T.
 * The same repeated number may be chosen from C unlimited number of times.
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set [2, 3, 6, 7] and target 7,
 * A solution set is:
 * [
 * [7],
 * [2, 2, 3]
 * ]
 */
public class _39_CombinationSum {
    /*
    https://segmentfault.com/a/1190000003743112
    可以参考这里的解题思路：分别介绍了类似的三个题目：Combination Sum ：I II III
    三道题思路差不多都是递归的方式（DFS）

    这种题本质上试DFS，解决办法是递归（深度遍历）
    1 首先进行排序
    2 递归搜索时，先加入，元素，再递归搜索，由于可以使用重复字符，则，下次递归的下标从当下开始
     */
    List<List<Integer>> ret;

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
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
                helper(nums, target - nums[i], i, temp);
                temp.remove(temp.size() - 1);
//                System.out.println("移除后：" + temp);

            }
        }
    }

    public static void main(String[] args) {
        _39_CombinationSum object = new _39_CombinationSum();
        int[] nums = {2, 3, 6, 7};
        System.out.println(object.combinationSum(nums, 7));
    }
}
