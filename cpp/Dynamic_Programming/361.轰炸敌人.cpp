/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 *
 * https://leetcode-cn.com/problems/count-numbers-with-unique-digits/description/
 *
 * Medium (47.39%)
 * 给定一个非负整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10^n 。
 *
 * 示例:
 * 输入: 2
 * 输出: 91
 * 解释: 答案应为除去 11,22,33,44,55,66,77,88,99 外，在 [0,100) 区间内的所有数字。
 */

// @lc code=start
class Solution {
   public:
    /*
    动态规划：
    1、n=0时：x=0， 结果为1
    2、n=1时：可以是0.1..9， 结果是10
    3、n=2时，第1位是1-9，共9个，第2位为0-9,去除第1位的一个，也是9，结果是9*9  9* (10-2+1)
    4、n=3时，第1位是1-9，共9个，第2位为0-9,去除第1位的一个，也是9，第3位是0-9去除前两位，共8种，结果是9*9*8,  为9*9*
    (10-3+1) 5...依次内推 当n>=2时， f(n) = f(n-1) *(10-n+1)
    */
    int countNumbersWithUniqueDigits(int n) {
        if (n==0) return 1;
        if (n == 1) return 10;
        int result = 10;
        int pre = 9;
        for (auto i = 2; i <= n; i++) {
            pre = pre * (10 - i + 1);
            result += pre;
        }
        return result;
    }
};
// @lc code=end
