/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode-cn.com/problems/powx-n/description/
 *
 * Medium (33.34%)
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 * 示例 1:
 * 输入: 2.00000, 10
 * 输出: 1024.00000
 * 示例 2:
 * 输入: 2.10000, 3
 * 输出: 9.26100
 *
 * 示例 3:
 * 输入: 2.00000, -2
 * 输出: 0.25000
 * 解释: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 说明:
 * -100.0 < x < 100.0
 * n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。
 *
 */

// @lc code=start
class Solution {
   public:
    /*
    二分查找
    暴力解法： 会超时
    这里对n做二分操作，最终乘法的次数未log2N
    */
    double myPow(double x, int n) {
        if (n == 0) return 1;

        bool negative = n < 0 ? true : false;
        long temp = n;
        temp = abs(temp);
        double half = myPow(x, temp / 2);
        double res = 1;
        if (n % 2 == 0)
            res = half * half;
        else
            res = half * half * x;
        if (negative) {
            return 1 / res;
        } else {
            return res;
        }
    }
};
// @lc code=end
