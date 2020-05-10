package leetcode;


import java.util.Arrays;

/**
 * author：baixiaoling
 * date: 2017/12/22
 * <p>
 * description:
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 * Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3.
 * It doesn't matter what you leave beyond the new length.
 */
public class _80_RemoveDuplicatesfromSortedArrayII {
    /*
    26题 RemoveDuplicatesfromSortedArray 基础上，添加一个记录重复元素个数的计数
     */
    public int removeDuplicates(int[] nums) {
        if (nums == null) return 0;
        if (nums.length <= 2) return nums.length;

        int count = 0;
        int index = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                count++;
                if (count >= 3) {
                    continue;
                }
            } else {
                count = 1;
            }
            nums[index++] = nums[i];
        }
        System.out.println(Arrays.toString(nums));
        return index;
    }

    public static void main(String[] args) {
        _80_RemoveDuplicatesfromSortedArrayII object = new _80_RemoveDuplicatesfromSortedArrayII();
        int[] nums = {1, 1, 1, 2, 2, 3, 3, 3};
        System.out.println(object.removeDuplicates(nums));
    }
}
