/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * [20] 有效的括号
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 * Easy (41.13%)
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 有效字符串需满足：
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 注意空字符串可被认为是有效字符串。
 * 示例 1:
 * 输入: "()"
 * 输出: true
 * 示例 2:
 * 输入: "()[]{}"
 * 输出: true
 *
 *
 * 示例 3:
 *
 * 输入: "(]"
 * 输出: false
 *
 *
 * 示例 4:
 *
 * 输入: "([)]"
 * 输出: false
 *
 *
 * 示例 5:
 *
 * 输入: "{[]}"
 * 输出: true
 *
 */

// @lc code=start
class Solution {
   public:
    bool isValid(string s) {
        if (s.size() == 0) {
            return true;
        }
        if (s.size() % 2 != 0) {
            return false;
        }
        stack<char> st;

        for (auto i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (s[i] == ')') {
                    if (st.empty() || st.top() != '(') {
                        return false;
                    }
                }
                if (s[i] == ']') {
                    if (st.empty() || st.top() != '[') {
                        return false;
                    }
                }
                if (s[i] == '}') {
                    if (st.empty() || st.top() != '{') {
                        return false;
                    }
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
// @lc code=end
