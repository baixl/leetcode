package leetcode;

/**
 * author：baixiaoling
 * date: 2017/12/13
 * <p>
 * description:
 */
public class _9_PalindromeNumber {
    /*
    判断一个数字是否是回文：
    不能使用额外空间，不能使用字符串，（字符串转置后和自己相等）
    解法：一次判断一个数字首位和末位是否相等
     */
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        int div = 1;
        while (x / div >= 10) {
            div *= 10;
        }
        while (x > 0) {
            int l = x / div;
            int r = x % 10;
            if (l != r) return false;
            x = (x % div) / 10; //取第2位
            div = div / 100;
        }
        return true;
    }

    public static void main(String[] args) {
        _9_PalindromeNumber obeject = new _9_PalindromeNumber();
        System.out.println(obeject.isPalindrome(11));
    }
}
