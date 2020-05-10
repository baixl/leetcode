/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * Medium (40.79%)
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 *
 * 示例 1:
 *
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 *
 * 示例 2:
 *
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 *
 * 说明：
 *
 *
 * num1 和 num2 的长度小于110。
 * num1 和 num2 只包含数字 0-9。
 * num1 和 num2 均不以零开头，除非是数字 0 本身。
 * 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 *
 *
 */

// @lc code=start
class Solution {
   public:
    /*
    相关题目： 415 字符串相加
    1、两个数字相乘，乘积的长度为 len1 + len2 或 len1 + len2 - 1
    2、使用模拟竖乘即可

     */
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int len1 = num1.size(), len2 = num2.size();
        vector<int> num(len1 + len2, 0);  // 存储乘积
        int product = 0, carry = 0;
        for (auto i = len1 - 1; i >= 0; i--) {
            carry = 0;  // 每一位相乘完毕，清空进位
            auto j = 0;
            for (j = len2 - 1; j >= 0; j--) {
                product = (num1[i] - '0') * (num2[j] - '0') + carry + num[i + j + 1];
                // num[i + j + 1] 为当前位置的值， 比如循环开始， i= len1 -1， j = len2 - 1, i+j+1 = len1 +len2 -1,
                // 为乘积的最低位的值
                carry = product / 10;
                num[i + j + 1] = product % 10;
            }
            num[i + j + 1] = carry;  //保留进位
        }

        string res = "";
        int i = 0;
        while (num[i] == 0) {
            i++;
        }

        for (; i < num.size(); i++) {
            res += to_string(num[i]);
        }
        // return carry == 0 ? res : to_string(carry) + res;
        return res;
    }
};
// @lc code=end
