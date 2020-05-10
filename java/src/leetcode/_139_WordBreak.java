package leetcode;

import java.util.*;

/**
 * author：baixiaoling
 * date: 2018/1/2
 * <p>
 * description:
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
 * determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 * You may assume the dictionary does not contain duplicate words.
 * <p>
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 * <p>
 * Return true because "leetcode" can be segmented as "leet code".
 * <p>
 * UPDATE (2017/1/4):
 * The wordDict parameter had been changed to a list of strings (instead of a set of strings).
 * Please reload the code definition to get the latest changes.
 * <p>
 * 解题思路：
 * http://blog.csdn.net/linhuanmars/article/details/22358863
 * <p>
 * 动态规划，关键是存储历史信息和如何用历史信息表示当前的值
 * <p>
 * 使用辅助数组 res ， res[i]表示到字符串s的第i个元素为止，能不能用字典中的词来表示
 * 使用一个长度为n的布尔数组来保存中间结果，假设已经获取了res[0....i-1]的值，现在需要获取res[i]
 * 对于每一个以i结尾的子串，看看其是否在字典里面，以及它之前元素对应的res是否为true。即
 * <p>
 * res[j]==true && s.substring(j, i+1) 在dict中
 */
public class _139_WordBreak {
    public boolean wordBreak(String s, List<String> wordDict) {
        if (s == null || s.length() == 0) return true;
        boolean[] res = new boolean[s.length() + 1];
        res[0] = true;

//        HashMap<String, Boolean> map = new HashMap<>();
//        for (String str : wordDict) {
//            map.put(str, true);
//        }
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j <= i; j++) {
                String string = s.substring(j, i + 1);

//                if (res[j] && map.containsKey(string)) {
                if (res[j] && wordDict.contains(string)) {
                    res[i + 1] = true;
                    break;
                }
            }
        }

//        System.out.println(Arrays.toString(res));
        return res[s.length()];
    }

    public static void main(String[] args) {
        _139_WordBreak object = new _139_WordBreak();
        List<String> list = new ArrayList<>();
        list.add("leet");
        list.add("code");
        System.out.println(object.wordBreak("leetcode", list));
    }
}
