package leetcode;

import java.util.HashSet;

/**
 * author：baixiaoling
 * date: 2017/12/8
 * <p>
 * description:
 * 解题思路：
 * 1.http://www.cnblogs.com/grandyang/p/4480780.html
 * 2. http://blog.csdn.net/likecool21/article/details/10858799
 * <p>
 * 题目地址：https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 * <p>
 * Given a string, find the length of the longest substring without repeating characters.
 * Examples:
 * <p>
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * <p>
 * Given "bbbbb", the answer is "b", with the length of 1.
 * <p>
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 */
public class _3_LongSubstringWithoutRepeatingCharacters {
    // 获取字符串最长不重复子序列的长度

    /*
    方法1：借助一个hashSet来维护当前的不重复子串（窗口），正常情况移动右窗口，每次移动左右窗口中的一个值
       1. 借助一个hashset维护一个窗口，保存当前有效的不重复子串结构
       2. right：有效不重复子串（窗口）右边一个字符在原始s的下标
       3. left：有效不重复子串（窗口）左边一个字符在原始s的下标
       hashSet中维护的是当前的有效不重复子串


     */
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }

        int left = 0; // 当前有效子串的第一个字符的位置
        int right = 0; // 当前有效子串的最后一个字符的位置
        int maxLength = 0;
        HashSet<Character> set = new HashSet<>();
        while (right < s.length()) {
            if (!set.contains(s.charAt(right))) {
                set.add(s.charAt(right));
                maxLength = Math.max(maxLength, set.size());
                right++;
            } else {
                //从set中移除s中重复字符和之前的字符，知道 set重新满足不重复位置
                set.remove(s.charAt(left));
                left++;
            }
        }

        return maxLength;
    }

    /*
        方法2：由于所有字符最多只会有256个AscII码， 可以用一个长度为256 的数组保存每个字符最后出现的下标
     */
    public int lengthOfLongestSubstring2(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        int[] table = new int[256];
        int left = -1;
        int maxLength = 0;
        for (int i = 0; i < table.length; i++) {
            table[i] = -1;
        }
        for (int i = 0; i < s.length(); i++) {
            left = Math.max(left, table[s.charAt(i)]); // 更新左边值的下标， 若该值以前已经出现过，则更新后的left为该值上一个位置的下标
            table[s.charAt(i)] = i; // 更新最后出现的下标
            maxLength = Math.max(maxLength, i - left);
        }
        return maxLength;
    }

    public static void main(String[] args) {
        String s = "tmmmzuxt";
        _3_LongSubstringWithoutRepeatingCharacters object = new _3_LongSubstringWithoutRepeatingCharacters();
        int length = object.lengthOfLongestSubstring2(s);
        System.out.println(length);
    }
}
