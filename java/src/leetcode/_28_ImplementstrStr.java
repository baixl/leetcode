package leetcode;

/**
 * author：baixiaoling
 * date: 2017/12/18
 * <p>
 * description:
 * Implement strStr().
 * Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * Example 1:
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * Example 2:
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 */
public class _28_ImplementstrStr {
    /*
    异常判断：
    needle为空，返回0
    needle长度大于 haystack长度，返回-1
    依次比较haystack和needle中的每个值 ，遍历的中终点是 haystack长度减去needle的长度

    更高级的解法：KMP方法 TODO
     */
    private int strStr(String haystack, String needle) {
        // 调用库函数
        //return haystack.indexOf(needle);
        if (needle == null || needle.length() == 0)
            return 0;
        int m = haystack.length(), n = needle.length();
        if (m < n)
            return -1;
        for (int i = 0; i <= m - n; i++) {
            int j;
            for (j = 0; j < n; j++) {
                if (haystack.charAt(i + j) != needle.charAt(j)) {
                    break;
                }
            }
            if (j == n)
                return i;
        }
        return -1;
    }

    public static void main(String[] args) {
        _28_ImplementstrStr object = new _28_ImplementstrStr();

        System.out.println(object.strStr("abc", "bc"));
    }
}
