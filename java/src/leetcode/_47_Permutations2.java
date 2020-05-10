package leetcode;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * author：baixiaoling
 * date: 2017/12/21
 * <p>
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 * For example,
 * [1,1,2] have the following unique permutations:
 * [
 * [1,1,2],
 * [1,2,1],
 * [2,1,1]
 * ]
 */
public class _47_Permutations2 {
    /*
    解题思路：递归 DFS
    需要注意的是，前面的数字也可以放到排列的后面，在递归时用一个visted标记
     */
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if (nums == null || nums.length == 0) return result;
        Arrays.sort(nums);
        helpDfs(nums, new boolean[nums.length], new ArrayList<Integer>(), result);
        return result;
    }

    private void helpDfs(int[] nums, boolean[] visited, ArrayList<Integer> list, List<List<Integer>> result) {
        if (list.size() == nums.length) {
            ArrayList<Integer> one = new ArrayList<Integer>(list);
            result.add(one);
            return;
        } else {
            for (int i = 0; i < nums.length; i++) {
                if (i > 0 && visited[i - 1] == false && nums[i] == nums[i - 1]) {
                    continue;
                }
                if (!visited[i]) {
                    visited[i] = true;
                    list.add(nums[i]);
                    helpDfs(nums, visited, list, result);
                    list.remove(list.size() - 1); // 恢复现场
                    visited[i] = false;
                }
            }
        }
    }

    public static void main(String[] args) {
        _47_Permutations2 object = new _47_Permutations2();
        int[] nums = {1, 1, 2};
        System.out.println(object.permuteUnique(nums));
    }
}
