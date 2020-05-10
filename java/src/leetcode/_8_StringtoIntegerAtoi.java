package leetcode;

/**
 * author：baixiaoling
 * date: 2017/12/13
 * <p>
 * description: atoi 是c++的字符串转整数函数
 */
public class _8_StringtoIntegerAtoi {
    public int myAtoi(String str) {
        if (str == null)
            return 0;
        str = str.trim();
        if (str.length() == 0)
            return 0;

        int sign = 1;
        int index = 0;
        if (str.startsWith("-")) {
            sign = -1;
            index++;
        } else if (str.startsWith("+")) {
            index++;
        }
        long ret = 0;
        for (int i = index; i < str.length(); i++) {
            if (str.charAt(i) < '0' || str.charAt(i) > '9')
                break;
            ret = ret * 10 + (str.charAt(i) - '0');
            if (ret > Integer.MAX_VALUE)
                break;
        }
        if (ret * sign > Integer.MAX_VALUE)
            return Integer.MAX_VALUE;
        if (ret * sign < Integer.MIN_VALUE)
            return Integer.MIN_VALUE;
        return (int) ret * sign;
    }

    public static void main(String[] args) {
        _8_StringtoIntegerAtoi object = new _8_StringtoIntegerAtoi();
        System.out.println(object.myAtoi("123"));
    }
}
