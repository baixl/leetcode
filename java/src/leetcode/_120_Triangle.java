package leetcode;

import java.util.List;

/**
 * author：baixiaoling
 * date: 2018/1/2
 * <p>
 * description:
 * Given a triangle, find the minimum path sum from top to bottom.
 * Each step you may move to adjacent numbers on the row below.
 * <p>
 * For example, given the following triangle
 * [
 * [2],
 * [3,4],
 * [6,5,7],
 * [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * <p>
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space,
 * where n is the total number of rows in the triangle.
 * 解题思路：
 * 动态规划
 * 每个节点只能向下和右下移动，通过动态规划维护一个到某元素的最小路径和的数组，最后遍历最后一层选一个最小的即可
 * <p>
 * 状态转移方程：sum[i][j] =  min(sum[i-1][j], sum[i-1][j]+ triangle[i][j]
 * 即当前节点的最小路径是上一层相邻元素最小路径加上自己
 * <p>
 * 这道题为了要求使用 O(n)， 可以使用自底向上的方式进行动态规划
 * 1 初始时dp初始化为最后一层的元素值
 * 2 依次向第一层遍历：dp[j] = Math.min(dp[j], dp[j + 1]) + triangle.get(i).get(j);
 */
public class _120_Triangle {
    public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle == null || triangle.size() == 0) return 0;
        if (triangle.size() == 1) return triangle.get(0).get(0);


        int[] dp = new int[triangle.get(triangle.size() - 1).size()];
        // 用最后一层元素初始化dp数组
        for (int i = 0; i < triangle.get(triangle.size() - 1).size(); i++) {
            dp[i] = triangle.get(triangle.size() - 1).get(i);
        }

        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j < triangle.get(i).size(); j++) {
                dp[j] = Math.min(dp[j], dp[j + 1]) + triangle.get(i).get(j);
            }
        }
        return dp[0];
    }
}
