/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 *
 * https://leetcode-cn.com/problems/count-and-say/description/
 *
 * Easy (53.03%)
 * 报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 1 被读作  "one 1"  ("一个一") , 即 11。
 * 11 被读作 "two 1s" ("两个一"）, 即 21。
 * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 * 给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
 * 注意：整数顺序将表示为一个字符串。
 *
 * 示例 1:
 * 输入: 1
 * 输出: "1"
 *
 * 示例 2:
 * 输入: 4
 * 输出: "1211"
 */

// @lc code=start
class Solution {
   public:
    /*
    前10项：
    1.     1
    2.     11
    3.     21
    4.     1211
    5.     111221
    6.     312211
    7.     13112221
    8.     1113213211
    9.     31131211131221
    10.    13211311123113112211

    1、先统计重复元素个数， 然后拼接结果
    2、递归处理
    */
    string countAndSay(int n) {
        if (n == 1) return "1";
        string res = "1";
        while (n != 1) {
            string temp = "";
            int len = res.size();
            int start = 1;
            while (start <= len) {
                int count = 1;  // 统计重复元素个数
                while (start < len && res[start] == res[start - 1]) {
                    count++;
                    start++;
                }
                temp += to_string(count) + res[start - 1];
                start++;
            }
            res = temp;
            n--;
        }
        return res;
    }
};
// @lc code=end
