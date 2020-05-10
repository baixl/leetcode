package leetcode;

import java.util.HashMap;
import java.util.Map;

/**
 * author：baixiaoling
 * date: 2018/1/12
 * <p>
 * description:
 * Find the length of the longest substring T of a given string (consists of lowercase letters only)
 * such that every character in T appears no less than k times.
 * Example 1:
 * Input:
 * s = "aaabb", k = 3
 * Output:
 * 3
 * The longest substring is "aaa", as 'a' is repeated 3 times.
 * Example 2:
 * Input:
 * s = "ababbc", k = 2
 * Output:
 * 5
 * <p>
 * The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 * <p>
 * 解题思路：分治
 * 1 统计字符串中各个字符的词频
 * 2 遍历字符串s，假设某个字符的词频小于k，则该字符肯定不在最终的子串中，
 * 3 在2基础上，分左右两支重复计算即可
 * <p>
 * 因为字符个数最多26，这里用一个字符数组统计各个字符的频数
 */
public class _395_LongestSubstringwithAtLeastKRepeatingCharacters {
    public int longestSubstring(String s, int k) {
        if (s == null || s.length() == 0 || k <= 0) return 0;
        return longestsub(s, k, 0, s.length() - 1);
    }

    private int longestsub(String s, int k, int start, int end) {
        //统计从start到end中每个char的词频
        if (start > end) {
            return 0;
        }
//        Map<Character, Integer> map =  new HashMap<>();
//        for
        int[] count = new int[26];
        for (int i = start; i <= end; i++) {
            count[s.charAt(i) - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] > 0 && count[i] < k) {
                int pos = s.indexOf((char) (i + 'a'), start);
                return Math.max(longestsub(s, k, start, pos - 1), longestsub(s, k, pos + 1, end));
            }
        }
        return end - start + 1;
    }

    public static void main(String[] args) {
        _395_LongestSubstringwithAtLeastKRepeatingCharacters object = new _395_LongestSubstringwithAtLeastKRepeatingCharacters();
        System.out.println(object.longestSubstring("weitong", 2));
    }
}
