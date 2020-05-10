package leetcode;

/**
 * author：baixiaoling
 * date: 2017/12/13
 * <p>
 * description:
 */
public class _7_ReverserInteger {
    public int reverse(int x) {
        if (x == 0) {
            return x;
        }
        int newx = Math.abs(x);
        int ret = 0;
        while (newx % 10 == 0) {
            newx /= 10;
        }
        while (newx != 0) {
            if (ret > (Integer.MAX_VALUE - newx % 10) / 10) { // 溢出处理
                return 0;
            }
            ret = ret * 10 + newx % 10;
            newx /= 10;

        }

        return x > 0 ? ret : -ret;
    }

    public int reverse2(int x) {
        long result = 0;
        int tmp = Math.abs(x);
        while (tmp > 0) {
            result *= 10;
            result += tmp % 10;
            if (result > Integer.MAX_VALUE) {
                return 0;
            }
            tmp /= 10;
        }
        return (int) (x >= 0 ? result : -result);
    }

    public static void main(String[] args) {
        _7_ReverserInteger object = new _7_ReverserInteger();
        System.out.println(object.reverse(123));
    }
}
