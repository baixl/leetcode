package leetcode;

import java.util.Random;

/**
 * author：baixiaoling
 * date: 2018/1/16
 * <p>
 * description:
 * Shuffle a set of numbers without duplicates.
 * <p>
 * Example:
 * <p>
 * // Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 * <p>
 * // Shuffle the array [1,2,3] and return its result.
 * Any permutation of [1,2,3] must equally likely to be returned.
 * solution.shuffle();
 * <p>
 * // Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 * <p>
 * // Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 */
public class _384_ShuffleanArray {

    int[] nums;
    Random random;

    public _384_ShuffleanArray(int[] nums) {
        this.nums = nums;
        this.random = new Random();
    }

    /**
     * Resets the array to its original configuration and return it.
     */
    public int[] reset() {
        return this.nums;

    }

    /**
     * Returns a random shuffling of the array.
     */
    public int[] shuffle() {
        if (this.nums == null) return nums;
        int[] newnums = nums.clone();

        for (int i = 0; i < newnums.length; i++) {
            int j = random.nextInt(i + 1);
            swap(newnums, i, j);
        }

        return newnums;

    }

    private void swap(int[] num, int i, int j) {
        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }
}
