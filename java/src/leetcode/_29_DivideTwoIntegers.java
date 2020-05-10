package leetcode;

/**
 * author：baixiaoling
 * date: 2017/12/18
 * <p>
 * description:
 * <p>
 * Divide two integers without using multiplication, division and mod operator.
 * If it is overflow, return MAX_INT.
 */
public class _29_DivideTwoIntegers {
    /*
    不能用乘除法和取余运算，我们只能使用位运算和加减法
    对于整数需要注意数字的边界问题，不能出现越界(int范围 -2147483648 ~ 2147483647）

    除法相当于 减去 除数持续左移动
     */
    public int divide(int dividend, int divisor) {
        if (divisor == 0)
            return Integer.MAX_VALUE;
        if (dividend == 0)
            return 0;
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            // -2147483648/-1 =2147483647
            return Integer.MAX_VALUE;
        }

        long dividend1 = Math.abs((long) dividend);
        long divisor1 = Math.abs((long) divisor);
        int result = 0;
        while (dividend1 >= divisor1) {
            int shift = 0;
            while ((divisor1 << shift) <= dividend1) {
                shift++;
            }
            result += 1 << (shift - 1);
            dividend1 -= divisor1 << (shift - 1);
        }
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
            return result;
        } else {
            return -result;
        }
    }

    public static void main(String[] args) {
        _29_DivideTwoIntegers object = new _29_DivideTwoIntegers();
        System.out.println(object.divide(1, 1));
    }
}
