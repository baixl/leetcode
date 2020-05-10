package leetcode;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * author：baixiaoling
 * date: 2017/12/16
 * <p>
 * description:
 */
public class _22_GenerateParentheses {
    /*
    递归
    思路：找左括号，
    1 每次遇到一个左括号，就在其后添加一对完整的括号
    2 在1之后，最后再在开头添加一个（）
     */
    public List<String> generateParenthesis(int n) {
        Set<String> set = new HashSet<>();
        List<String> list = new ArrayList<>();
        if (n == 0) {
            set.add("");
        } else {
            List<String> pre = generateParenthesis(n - 1);
            for (String str : pre) {
                for (int i = 0; i < str.length(); i++) {
                    if (str.charAt(i) == '(') {
                        String s = str.substring(0, i + 1) + "()" + str.substring(i + 1, str.length());
                        set.add(s);
                    }
                }
                set.add("()" + str);
            }

        }
        return new ArrayList<>(set);
    }


    public static void main(String[] args) {
        _22_GenerateParentheses object = new _22_GenerateParentheses();
        System.out.println(object.generateParenthesis(3));
    }
}
