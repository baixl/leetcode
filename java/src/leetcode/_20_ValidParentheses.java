package leetcode;

import java.util.LinkedList;

/**
 * author：baixiaoling
 * date: 2017/12/16
 * <p>
 * description:
 */
public class _20_ValidParentheses {
    /*
    使用一个栈来保存括号，用java的linkedlist模拟栈
    1 若是左括号，直接入栈
    2 若是右括号，
        1）若栈为空，直接返回false
        2）若左右扩号匹配，直接弹出栈顶b元素
        3）若不匹配，返回false
     */
    public boolean isValid(String s) {
        if (s == null || s.length() == 0) return true;
        LinkedList<Character> list = new LinkedList<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '{') {
                list.addFirst('{');
            } else if (s.charAt(i) == '(') {
                list.addFirst('(');
            } else if (s.charAt(i) == '[') {
                list.addFirst('[');
            } else if (s.charAt(i) == '}') {
                if (list == null || list.size() == 0)
                    return false;
                else if (list.getFirst() == '{')
                    list.removeFirst();
                else
                    return false;
            } else if (s.charAt(i) == ')') {
                if (list == null || list.size() == 0)
                    return false;
                else if (list.getFirst() == '(')
                    list.removeFirst();
                else
                    return false;
            } else if (s.charAt(i) == ']') {
                if (list == null || list.size() == 0)
                    return false;
                else if (list.getFirst() == '[')
                    list.removeFirst();
                else
                    return false;
            }
        }
        return list.size() == 0 ? true : false;
    }

    public static void main(String[] args) {
        _20_ValidParentheses object = new _20_ValidParentheses();
        boolean ret = object.isValid("(])");
        System.out.println(ret);
    }
}
