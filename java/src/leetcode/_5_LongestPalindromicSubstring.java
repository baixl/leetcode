package leetcode;

/**
 * author：baixiaoling
 * date: 2017/12/12
 * <p>
 * description: 最长回文子串
 */
public class _5_LongestPalindromicSubstring {
    private int max = 0;
    private String ret = "";

    // 最长回文子串 方法1 ：中心扩展法
    public String longestPalindrome(String s) {
        if (s == null || s.length() <= 1) {
            return s;
        }
        for (int i = 0; i < s.length() - 1; i++) {
            //需要检查 aba  和abba两种情况
            checkPalindrome(s, i, i);
            checkPalindrome(s, i, i + 1);
        }
        return ret;
    }

    public void checkPalindrome(String s, int left, int right) {
        while (left >= 0 && right < s.length()) {
            if (s.charAt(left) == s.charAt(right)) {
                if (right - left + 1 > max) {
                    max = right - left + 1;
                    ret = s.substring(left, right + 1);
                }
                left--;
                right++;
            } else {
                return;
            }

        }
    }

    /*
    Manacher算法：专门用于计算最长回文的算法
    http://xlbai.site/2016/08/04/algorithm/%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2%EF%BC%88Manacher%E7%AE%97%E6%B3%95%EF%BC%89/
    1 将字符串统一转换成奇数长度：以# 拼接
    2 求转换后字符的回文半径数组p
    3 p[i]-1就是转换后字符串对应位置的回文长度。

     */
    public String manacher(String s) {
        s = change(s);
        int[] p = new int[s.length()];
        int mx = -1; // 已知的回文的右边边界
        int id = -1; // 已知的回文中点坐标
        for (int i = 0; i < s.length(); i++) {
            if (mx > i) {
                p[i] = Math.min(mx - i, p[2 * id - i]);
            } else {
                p[i] = 1;
            }
            // 尝试更大半径
            while (i - p[i] >= 0 && i + p[i] < s.length()
                    && s.charAt(i - p[i]) == s.charAt(i + p[i])) {
                p[i]++;
            }
            // 更新边界和回文中心坐标
            if (i + p[i] > mx) {
                mx = p[i] + i;
                id = i;
            }
        }
        max = 0;
        ret = "";
//        System.out.println(Arrays.toString(p));
//        System.out.println(s);
        for (int i = 0; i < p.length; i++) {
            if (p[i] > max) {
                max = p[i];
                ret = s.substring(i - p[i] + 1, i + p[i] - 1);
            }
        }
        return ret.replace("#", "");
    }

    public String change(String s) {
        StringBuilder sb = new StringBuilder();
        sb.append("#");
        for (int i = 0; i < s.length(); i++) {
            sb.append(s.charAt(i)).append("#");
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        _5_LongestPalindromicSubstring object = new _5_LongestPalindromicSubstring();
        String s = object.manacher("bb");
        System.out.println(s);
    }

}
