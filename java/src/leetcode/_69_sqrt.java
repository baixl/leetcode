package leetcode;

/**
 * author：baixiaoling
 * date: 2017/12/30
 * <p>
 * description:
 * Implement int sqrt(int x).
 * <p>
 * Compute and return the square root of x.
 * <p>
 * x is guaranteed to be a non-negative integer.
 * <p>
 * Example 1:
 * <p>
 * Input: 4
 * Output: 2
 * Example 2:
 * <p>
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842...,
 * and since we want to return an integer, the decimal part will be truncated.
 * 解题思路：
 * 二分查找
 */
public class _69_sqrt {
    public int mySqrt(int x) {
        if (x <= 1) return x;

        int left = 1, right = x / 2;
        int result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid < x / mid) {  // mid * mid 有可能溢出
                left = mid + 1;
                result = mid;
            } else if (mid > x / mid) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        _69_sqrt object = new _69_sqrt();
        System.out.println(object.mySqrt(16));
    }
}
