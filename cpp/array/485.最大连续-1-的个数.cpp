/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 * https://leetcode-cn.com/problems/max-consecutive-ones/description/
 * Easy (54.64%)
 * 给定一个二进制数组， 计算其中最大连续1的个数。
 * 示例 1:
 * 输入: [1,1,0,1,1,1]
 * 输出: 3
 * 解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
 * 注意：
 * 输入的数组只包含 0 和1。
 * 输入数组的长度是正整数，且不超过 10,000。
 */
class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = 0;
        int temp = 0;
        for (auto i = 0; i < nums.size(); i++) {
            if (i == 0) {
                if (nums[i] == 1) {
                    temp = res = 1;
                }
            } else {
                if (nums[i] == 1) {
                    temp += 1;
                    res = max(res, temp);
                } else {
                    temp = 0;
                }
            }
        }
        return res;
    }
};
