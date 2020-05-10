package leetcode;

import java.util.LinkedList;
import java.util.List;

/**
 * author：baixiaoling
 * date: 2017/12/20
 * <p>
 * description:
 * Find all possible combinations of k numbers that add up to a number n,
 * given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 * Example 1:
 * Input: k = 3, n = 7
 * Output:
 * [[1,2,4]]
 * Example 2:
 * Input: k = 3, n = 9
 * Output:
 * [[1,2,6], [1,3,5], [2,3,4]]
 */
public class _216_CombinationSumIII {
    /*
    和第39题 第40题类似：
    https://segmentfault.com/a/1190000003743112
    可以参考这里的解题思路：分别介绍了类似的三个题目：Combination Sum ：I II III
    三道题思路差不多都是递归的方式（DFS）

    这种题本质上试DFS，解决办法是递归（深度遍历）
    解题思路：
    这道题的待选项是 1-9这9个数字，且不存在重复，递归时注意个数是k
    1 首先进行排序
    2 递归搜索时，先加入，元素，再递归搜索，递归时每次需要添加k（-1）
     */
    List<List<Integer>> ret;

    public List<List<Integer>> combinationSum3(int k, int n) {
        ret = new LinkedList<>();
        int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        List<Integer> temp = new LinkedList<>();
        helper(nums, n, k, 0, temp);
        return ret;
    }

    private void helper(int[] nums, int target, int k, int index, List<Integer> temp) {
        if (target < 0 || k < 0) {
            return;
        }
        if (target == 0 && k == 0) {
            List<Integer> one = new LinkedList<>(temp);
            ret.add(one);
        } else {
            //递归处理
            for (int i = index; i < nums.length; i++) {
                temp.add(nums[i]);
                helper(nums, target - nums[i], k - 1, i + 1, temp);
                temp.remove(temp.size() - 1);
            }
        }
    }

    public static void main(String[] args) {
        _216_CombinationSumIII object = new _216_CombinationSumIII();
        System.out.println(object.combinationSum3(3, 100));
    }

}
