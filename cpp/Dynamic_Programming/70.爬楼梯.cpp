/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70]爬楼梯
 */
class Solution {
   public:
    int climbStairs(int n) {
        if (n <= 0) {
            return 0;
        };
        if (n == 1) {
            return 1;
        };
        if (n == 2) {
            return 2;
        };

        int sum = 0, sum1, sum2;
        sum1 = 1;
        sum2 = 2;
        for (int i = 2; i < n; i++) {
            sum = sum1 + sum2;
            sum1 = sum2;
            sum2 = sum;
        }
        return sum;
    }
};
