/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 *
 * https://leetcode-cn.com/problems/add-strings/description/
 *
 * Easy (48.04%)
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
 *
 * 注意：
 *
 *
 * num1 和num2 的长度都小于 5100.
 * num1 和num2 都只包含数字 0-9.
 * num1 和num2 都不包含任何前导零。
 * 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
 *
 *
 */

// @lc code=start
class Solution {
   public:
    string addStrings(string num1, string num2) {
        if (num1.empty()) return num2;
        if (num2.empty()) return num1;
        int len1 = num1.size(), len2 = num2.size(), i = len1 - 1, j = len2 - 1;
        int carry = 0;
        string res = "";
        while (i >= 0 && j >= 0) {
            int temp = carry + (num1[i] - '0') + (num2[j] - '0');
            carry = temp / 10;
            temp = temp % 10;
            res += to_string(temp);
            i--;
            j--;
        }
        while (i >= 0) {
            int temp = carry + (num1[i] - '0');
            carry = temp / 10;
            temp = temp % 10;
            res += to_string(temp);
            i--;
        }
        while (j >= 0) {
            int temp = carry + (num2[j] - '0');
            carry = temp / 10;
            temp = temp % 10;
            res += to_string(temp);
            j--;
        }
        if (carry != 0) res += to_string(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
