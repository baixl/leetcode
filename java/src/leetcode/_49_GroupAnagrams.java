package leetcode;

import java.util.*;

/**
 * author：baixiaoling
 * date: 2017/12/21
 * <p>
 * description:
 * Given an array of strings, group anagrams together.
 * <p>
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Return:
 * [
 * ["ate", "eat","tea"],
 * ["nat","tan"],
 * ["bat"]
 * ]
 */
public class _49_GroupAnagrams {
    /*
    思路：将同组的字符串放到hash中的同一个key下
    方法1：排序法，同一组的字符串排序后相同，可以将排序后的字符串当成key
    方法2： 素数乘法。用26个数组表示26个字母，则每个字符串都可以用素数的乘积表示，由于素数的性质,不同字母构成的字符串积不同
     */

    /*
    方法1 ：hash排序法
     */
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
        for (int i = 0; i < strs.length; i++) {
            char[] strArr = strs[i].toCharArray();
            Arrays.sort(strArr);
            String sortedAtr = new String(strArr);
            if (map.get(sortedAtr) != null) {
                map.get(sortedAtr).add(strs[i]);
            } else {
                List<String> list = new ArrayList<String>();
                list.add(strs[i]);
                map.put(sortedAtr, list);
            }

        }
        List<List<String>> lists = new ArrayList<>();
        for (Map.Entry<String, List<String>> entry : map.entrySet()) {
            lists.add(entry.getValue());
        }
        return lists;
    }

    /*
    方法1 ：素数乘积法
     */
    public List<List<String>> groupAnagrams2(String[] strs) {
        int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};

        Map<Integer, List<String>> map = new HashMap<>();
        for (int i = 0; i < strs.length; i++) {
            int mulit = 1;
            char[] strArr = strs[i].toCharArray();
            for (int j = 0; j < strArr.length; j++) {
                mulit *= primes[strArr[j] - 'a'];
            }
            if (map.get(mulit) != null) {
                map.get(mulit).add(strs[i]);
            } else {
                List<String> list = new ArrayList<String>();
                list.add(strs[i]);
                map.put(mulit, list);
            }

        }
        List<List<String>> lists = new ArrayList<>();
        for (Map.Entry<Integer, List<String>> entry : map.entrySet()) {
            lists.add(entry.getValue());
        }
        return lists;
    }
}
