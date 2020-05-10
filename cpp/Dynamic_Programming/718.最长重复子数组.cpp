/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 * https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/description/
 *
 * Medium (46.80%)
 * 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
 * 示例 1:
 * 输入:
 * A: [1,2,3,2,1]
 * B: [3,2,1,4,7]
 * 输出: 3
 * 解释:
 * 长度最长的公共子数组是 [3, 2, 1]。
 * 说明:
 *
 * 1 <= len(A), len(B) <= 1000
 * 0 <= A[i], B[i] < 100
 *
 *
 */

// @lc code=start
class Solution {
   public:
    /*
    这个和最长公共子串长度一样
    动态规划：新建动态规划表dp[i][j]
    dp[i][j]表示以 A[i] 与B[j]结尾的数组， 最长公共子数组的长度
    当A[i] == B[j]时， dp[i][j] = dp[i - 1][j - 1] + 1;
    当A[i] != B[j]时， 则 A[i] 和B[j]结尾的字符串不是公共子串，则dp[i][j] = 0;

    时间：O(M+N) 空间O(M+N)
    */
    int findLength(vector<int>& A, vector<int>& B) {
        if (A.size() == 0 || B.size() == 0) return 0;
        int len1 = A.size(), len2 = B.size();
        vector<vector<int>> dp(len1, vector<int>(len2, 0));
        // 第1列
        int result = INT_MIN;
        for (auto i = 0; i < len1; i++) {
            if (A[i] == B[0]) {
                dp[i][0] = 1;
                result = 1;
            }
        }
        for (auto j = 0; j < len2; j++) {
            if (A[0] == B[j]){
                 dp[0][j] = 1;
                 result = 1;
            }
        }
        for (auto i = 1; i < len1; i++) {
            for (auto j = 1; j < len2; j++) {
                if (A[i] == B[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = 0;
                }
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }
};
// @lc code=end
