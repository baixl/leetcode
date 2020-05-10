/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 * Medium (47.38%)
 * 编写一个程序，找出第 n 个丑数。
 * 丑数就是只包含质因数 2, 3, 5 的正整数。
 * 示例:
 * 输入: n = 10
 * 输出: 12
 * 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 * 说明:  
 * 1 是丑数。
 * n 不超过1690。
 */

// @lc code=start
class Solution {
   public:
    /*
    动态规划  
    */
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        int l2 = 0, l3 = 0, l5 = 0;
        for (auto i = 1; i < n; i++) {
            int min_val = min(min(2 * dp[l2], 3 * dp[l3]), 5 * dp[l5]);
            if (min_val == 2 * dp[l2]) l2++;
            if (min_val == 3 * dp[l3]) l3++;
            if (min_val == 5 * dp[l5]) l5++;
            dp[i] = min_val;
        }
        return dp[n-1];
    }
};
// @lc code=end
