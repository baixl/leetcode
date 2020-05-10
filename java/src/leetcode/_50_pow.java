package leetcode;

/**
 * author：baixiaoling
 * date: 2017/12/21
 * <p>
 * description:
 */
public class _50_pow {
    /*
    递归，折半处理
     */
    public double myPow(double x, int n) {
        if (n < 0) {
            return 1 / pow(x, -n);
        }
        return pow(x, n);

    }

    private double pow(double x, int n) {
        if (n == 0) return 1;
        double half = pow(x, n / 2);
        if (n % 2 == 0) return half * half;
        return x * half * half;

    }
}
