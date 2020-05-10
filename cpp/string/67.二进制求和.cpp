/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * Easy (51.14%)
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。

 * 输入为非空字符串且只包含数字 1 和 0。
 *
 * 示例 1:
 *
 * 输入: a = "11", b = "1"
 * 输出: "100"
 *
 * 示例 2:
 *
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 *
 */

// @lc code=start
class Solution {
   public:
    string addBinary(string a, string b) {
        if (a.empty()) return b;
        if (b.empty()) return a;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int len1 = a.size(), i = 0;
        int len2 = b.size(), j = 0;
        int carry = 0;
        string res = "";
        while (i < len1 && j < len2) {
            int temp = carry + (a[i] - '0') + (b[j] - '0');
            carry = temp / 2;
            temp = temp % 2;
            res += to_string(temp);
            i++, j++;
        }
        while (i < len1) {
            int temp = carry + (a[i] - '0');
            carry = temp / 2;
            temp = temp % 2;
            res += to_string(temp);
            i++;
        }
        while (j < len2) {
            int temp = carry + (b[j] - '0');
            carry = temp / 2;
            temp = temp % 2;
            res += to_string(temp);
            j++;
        }
        if (carry != 0) res += to_string(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
