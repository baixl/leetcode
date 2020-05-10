/*
 * @lc app=leetcode.cn id=343 lang=cpp
 * [343] 整数拆分
 * https://leetcode-cn.com/problems/integer-break/description/
 *
 * Medium (52.61%)
 * 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
 * 示例 1:
 * 输入: 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 * 示例 2:
 * 输入: 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 *
 * 说明: 你可以假设 n 不小于 2 且不大于 58。
 *
 */

// @lc code=start
class Solution {
   public:
    /*
    解法1：https://leetcode-cn.com/problems/integer-break/solution/tan-xin-xuan-ze-xing-zhi-de-jian-dan-zheng-ming-py/
    最终可以拆解成 因子2 3 的和，且3的优先级更高，看原始解答
    */
    int integerBreak1(int n) {
        if (n == 1) return 1;
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        int res = 1;
        while (n > 4) {
            res *= 3;
            n -= 3;
        }
        res *= n;
        return res;
    }
    /*
    方法2：动态规划 有两层循环，时间O(n2) 空间O(n)
    */
    int integerBreak(int n) {
        if (n == 1) return 1;
        if (n == 2) return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (auto i = 2; i < n + 1; i++) {
            for (auto j = 1; j < i; j++) {
                dp[i] = max(dp[i], j * dp[i - j]);
                dp[i] = max(dp[i], j * (i - j));
            }
        }
        return dp[n];
    }
};
// @lc code=end
