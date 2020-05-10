package leetcode;

import java.util.Arrays;
import java.util.Comparator;

/**
 * author：baixiaoling
 * date: 2018/1/16
 * <p>
 * description:
 * Given a list of non negative integers, arrange them such that they form the largest number.
 * <p>
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 * <p>
 * Note: The result may be very large, so you need to return a string instead of an integer.
 * <p>
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 * <p>
 * 解题思路：
 * 这道题的意思就是，给定一个非负数数组，要求其组合成的整数字符串的最大值。
 * 1  首先想到的是先对数组排序，但这里的排序规则不能按照数字大小排序，
 * 比如 9，在数字大小排序时，可能排在中间，但是最终这个值肯定在字符串的头部
 * 2 也不能按照字符串的长度排序，比如，3 与30，长度排序时 30 > 3 但是结果 303 <330
 * 3 这道题的排序规则是，若ab>ba ,则a更应该作为结果的高位，b作为低位
 * 注意数组全是0 的情况，比如[0, 0]
 */
public class _179_LargestNumber {
    public String largestNumber(int[] nums) {
        String[] strs = new String[nums.length];
        for (int i = 0; i < nums.length; i++) {
            strs[i] = String.valueOf(nums[i]);
        }
        Arrays.sort(strs, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return (o1 + o2).compareTo(o2 + o1);
            }
        });


        StringBuilder sb = new StringBuilder();
        for (int i = strs.length - 1; i >= 0; i--) {
            sb.append(strs[i]);
        }
        while (sb.charAt(0) == '0' && sb.length() > 1)
            sb.deleteCharAt(0);
        return sb.toString();
    }

    public static void main(String[] args) {
        int[] nums = {3, 30, 34, 5, 9};
        _179_LargestNumber object = new _179_LargestNumber();
        System.out.println(object.largestNumber(nums));
    }


}
