/*
 * @lc app=leetcode.cn id=279 lang=cpp
 * [279] 完全平方数
 * https://leetcode-cn.com/problems/perfect-squares/description/
 * Medium (50.74%)
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 *
 * 示例 1:
 *
 * 输入: n = 12
 * 输出: 3
 * 解释: 12 = 4 + 4 + 4.
 *
 * 示例 2:
 *
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 *
 */

// @lc code=start
class Solution {
   public:
    /*
    动态规划
    1、新建长度为n+1的数组dp,每个位置为0，
    2、对数组进行遍历，初始化，dp[i] = i,表示最差情况下，dp[i] 由i个1组成
    3、动态规划，dp[i] 可以表示成i减去一个平方数+1 （+1的意思是，当i是平方数时，dp[i] ==1）:
        dp[i] = min(dp[i], dp[i - j * j] + 1);
    */
    int numSquares(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        vector<int> dp(n + 1, 0);
        // dp[1] = 1;
        // 初始化，dp[i] = i; n的最大值 组合 1、1、1..., n个1
        for (auto i = 1; i <= n; i++) {
            dp[i] = i;                           // 最差情况
            for (auto j = 1; j * j <= i; j++) {  //转移方程
                // 意思就是，每一个平方数：dp[i] =1， 减去一个平方数后对应的结果是 dp[i - j * j]
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end
