package leetcode;

/**
 * author：baixiaoling
 * date: 2018/1/4
 * <p>
 * description:
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * <p>
 * Each element in the array represents your maximum jump length at that position.
 * <p>
 * Determine if you are able to reach the last index.
 * <p>
 * For example:
 * A = [2,3,1,1,4], return true.
 * <p>
 * A = [3,2,1,0,4], return false.
 * <p>
 * 解题思路：
 * 遍历数组，记录每个位置能到达的最大位置
 * 1 当前最大位置>= 最后一个位置，返回true
 * 2 当前最大位置<全局最大位置，继续
 * 3 当前最大位置等于全局最大位置，但当前位置step为0， 返回false
 */
public class _55_JumpGame {
    public boolean canJump(int[] nums) {
        if (nums == null) return false;
        if (nums.length <= 1) return true;
        int maxTo = 0; // 全局最大位置
        for (int i = 0; i < nums.length; i++) {
            int step = nums[i];
            int to = i + step; // 当前能到的最大位置
            if (to <= maxTo) {
                if (to == maxTo && step == 0) {
                    return false;
                }
                continue;
            } else {
                maxTo = to;
            }

            if (maxTo >= nums.length - 1)
                return true;
        }
        return false;
    }

    public static void main(String[] args) {
        _55_JumpGame object = new _55_JumpGame();
        int[] num = {3, 0, 8, 2, 0, 0, 1};
        System.out.println(object.canJump(num));
    }
}
