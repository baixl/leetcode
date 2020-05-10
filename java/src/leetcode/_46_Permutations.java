package leetcode;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * author：baixiaoling
 * date: 2017/12/21
 * <p>
 * description:
 * Given a collection of distinct numbers, return all possible permutations.
 * For example,
 * [1,2,3] have the following permutations:
 * [
 * [1,2,3],
 * [1,3,2],
 * [2,1,3],
 * [2,3,1],
 * [3,1,2],
 * [3,2,1]
 * ]
 */
public class _46_Permutations {
    /*
    解题思路：递归 DFS
    需要注意的是，前面的数字也可以放到排列的后面，在递归时用一个visted标记
     */


    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if (nums == null || nums.length == 0) return result;
        helpDfs(nums, new boolean[nums.length], new ArrayList<Integer>(), result);
        return result;
    }

//    private void helpDfs(int[] nums, boolean[] booleans, ArrayList<Integer> integers, List<List<Integer>> result) {
//    }


    private void helpDfs(int[] nums, boolean[] visited, ArrayList<Integer> list, List<List<Integer>> result) {
        if (list.size() == nums.length) {
            ArrayList<Integer> one = new ArrayList<Integer>(list);
            result.add(one);
            return;
        } else {
            for (int i = 0; i < nums.length; i++) {
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
        _46_Permutations object = new _46_Permutations();
        int[] nums = {1, 2, 3};
        System.out.println(object.permute(nums));
    }
}
