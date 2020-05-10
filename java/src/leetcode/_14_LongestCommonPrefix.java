package leetcode;

/**
 * author：baixiaoling
 * date: 2017/12/13
 * <p>
 * description:https://leetcode.com/problems/longest-common-prefix/description/
 */
public class _14_LongestCommonPrefix {
    /*
     求一组字符串的最长公共前缀
     1. 求最短字符串长度
     2. 遍历所有字符串，
      */
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0)
            return "";
        if (strs.length == 1) {
            return strs[0];
        }
        int minLegnth = Integer.MAX_VALUE;
        for (int i = 0; i < strs.length; i++) {
            if (strs[i].length() < minLegnth) {
                minLegnth = strs[i].length();
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < minLegnth; i++) {
            boolean flag = true;
            char currentChar = strs[0].charAt(i);
            for (int j = 1; j < strs.length; j++) {
                if (strs[j].charAt(i) != currentChar) {
                    flag = false;
                    break;
                }
            }
            if (flag == false) {
                return sb.toString();
            }
            sb.append(currentChar);
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        _14_LongestCommonPrefix object = new _14_LongestCommonPrefix();
        String[] s = {"abb", "abc"};
        System.out.println(object.longestCommonPrefix(s));
    }
}
