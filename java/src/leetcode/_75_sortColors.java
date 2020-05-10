package leetcode;

import java.util.Arrays;

/**
 * author：baixiaoling
 * date: 2017/12/25
 * <p>
 * description:
 * Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 */
public class _75_sortColors {
    /*
    不能使用库函数，发现调用 Arrays.sort(nums); 也能AC
        方法1：计数排序， 依次统计0，1，2的数量然后依次插入
     */
    public void sortColors(int[] nums) {
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) count0++;
            if (nums[i] == 1) count1++;
            if (nums[i] == 2) count2++;
        }

        for (int i = 0; i < nums.length; i++) {
            if (i < count0) {
                nums[i] = 0;
            } else if (i < count0 + count1) {
                nums[i] = 1;
            } else {
                nums[i] = 2;
            }
        }
        System.out.println(Arrays.toString(nums));
    }

    public void s(int i, int k, int[] c) {
        int temp = c[i];
        c[i] = c[k];
        c[k] = temp;
    }

    public void sortColors2(int[] nums) {
        int r, b, j, red, blue;

        blue = 2;
        red = r = j = 0;
        b = nums.length - 1;


        while (b >= j) {
            if (nums[j] == red) {
                s(j, r, nums);
                r = r + 1;
                j++;
            } else if (nums[j] == blue) {
                s(j, b, nums);
                b = b - 1;
            } else {
                j++;
            }
        }
    }

    public static void main(String[] args) {
        _75_sortColors object = new _75_sortColors();
        int[] nums = {0, 1, 0, 2, 1, 0};
        object.sortColors(nums);
    }

}
