package leetcode;

import java.util.ArrayList;
import java.util.List;
import java.util.SplittableRandom;

/**
 * author：baixiaoling
 * date: 2018/1/1
 * <p>
 * description:
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * <p>
 * Return all possible palindrome partitioning of s.
 * <p>
 * For example, given s = "aab",
 * Return
 * <p>
 * [
 * ["aa","b"],
 * ["a","a","b"]
 * ]
 * <p>
 * 解题思路：
 * https://www.kancloud.cn/kancloud/data-structure-and-algorithm-notes/73059
 * DFS 。使用插板法:在字符串中每个间隙插入一个隔板，长度为n的字符串共有n-1个隔板
 * 从第一个隔板挨个往后取，若取到的字符串是回文，则将其放入临时列表，继续向后走，若不是回文则跳过，继续向后走
 */
public class _131_PalindromePartitioning {
    public List<List<String>> partition(String s) {
        List<List<String>> result = new ArrayList<>();
        if (s == null || s.length() == 0) return result;
        List<String> palindroms = new ArrayList<>();
        dfs(s, 0, palindroms, result);
        return result;
    }

    private void dfs(String s, int pos, List<String> palindroms, List<List<String>> ret) {
        if (pos == s.length()) {
            ret.add(new ArrayList<>(palindroms));
            return;
        }
        for (int i = pos; i <= s.length(); i++) {
            String subStr = s.substring(pos, i);
            if (!isPalindrome(subStr)) continue;
            palindroms.add(subStr);
            dfs(s, i, palindroms, ret);
            palindroms.remove(palindroms.size() - 1); // 恢复现场
        }
    }

    private boolean isPalindrome(String s) {
        if (s == null || s.length() == 0) return false;
        int n = s.length() - 1;
        for (int i = 0; i < (n + 1) / 2; i++) {
            if (s.charAt(i) != s.charAt(s.length() - 1 - i)) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        _131_PalindromePartitioning object = new _131_PalindromePartitioning();
        System.out.println(object.partition("abbaa"));

    }
}
