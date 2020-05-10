package leetcode;

/**
 * author：baixiaoling
 * date: 2018/1/4
 * <p>
 * description:
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * Note: Given n will be a positive integer.
 * Example 1:
 * <p>
 * Input: 2
 * Output:  2
 * Explanation:  There are two ways to climb to the top.
 * <p>
 * 1. 1 step + 1 step
 * 2. 2 steps
 * Example 2:
 * <p>
 * Input: 3
 * Output:  3
 * Explanation:  There are three ways to climb to the top.
 * <p>
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 * <p>
 * 解题思路:
 */
public class _70_ClimbingStairs {
    public int climbStairs(int n) {
        int a = 1;
        int b = 2;
        if (n == 1) return a;
        if (n == 2) return b;
        int c = 0;
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }

    public static void main(String[] args) {
        _70_ClimbingStairs object = new _70_ClimbingStairs();
        System.out.println(object.climbStairs(4));
    }
}
