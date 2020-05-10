package leetcode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * author：baixiaoling
 * date: 2017/12/13
 * <p>
 * description:
 */
public class _17_LetterCombinationsofPhoneNumber {
    // TODO  这需要一个递归过程
    public List<String> letterCombinations(String digits) {
        String[] hash = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        ArrayList<String> ret = new ArrayList<>();
        if (digits == null || digits.length() == 0)
            return ret;

        letterComb(ret, digits.length(), hash, digits, new StringBuilder());
        return ret;
    }

    // 递归计算
    public void letterComb(ArrayList<String> ret, int remain, String[] hash, String dights, StringBuilder sb) {
        if (remain == 0) {
            ret.add(sb.toString());
            return;
        }
        String s = hash[dights.charAt(0) - '0'];
        for (int i = 0; i < s.length(); i++) {
            sb = sb.append(s.charAt(i));
            // 递归
            letterComb(ret, remain - 1, hash, dights.substring(1), sb);
            sb.deleteCharAt(sb.length() - 1);  // 恢复现场
        }
    }


    /*
    方法2：
     */
    private static final String[] LETTERS = new String[]{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    public List<String> letterCombinations2(String digits) {

        List<String> res = new LinkedList<>();

        if (digits.length() == 0) return res;

        letterCombinationsHelper(digits, res, "", 0);

        return res;
    }

    private void letterCombinationsHelper(String digits, List<String> res, String cur, int i) {
        if (i == digits.length()) {
            res.add(cur);
            return;
        }

        String str = LETTERS[digits.charAt(i) - '0'];

        for (char c : str.toCharArray()) {
            letterCombinationsHelper(digits, res, cur + c, i + 1);
        }
    }

    public static void main(String[] args) {
        _17_LetterCombinationsofPhoneNumber object = new _17_LetterCombinationsofPhoneNumber();
        System.out.println(object.letterCombinations("23"));
    }
}
