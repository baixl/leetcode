/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 *
 * https://leetcode-cn.com/problems/valid-perfect-square/description/
 *
 * Easy (42.17%)
 * 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
 *
 * 说明：不要使用任何内置的库函数，如  sqrt。
 *
 * 示例 1：
 *
 * 输入：16
 * 输出：True
 *
 * 示例 2：
 *
 * 输入：14
 * 输出：False
 *
 *
 */

// @lc code=start
class Solution {
   public:
    /*
    二分查找
    */
    bool isPerfectSquare(int num) {
        if (num <= 0) return false;
        if (num == 1) return true;
        int left = 1, right = num;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long temp = mid * mid;  // 乘法可能超出了int的最大值
            if (temp == num) return true;
            if (temp < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end
