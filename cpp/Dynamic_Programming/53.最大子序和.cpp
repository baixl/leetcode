/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
class Solution {
   public:
   // 动态规划：
   // 记录到当前位置的最大和temp。 如果前一个位置 temp > 0 : 转移方程： temp += nums[i]
   // 如果 前一个位置 temp < 0;  则最大和为当前元素
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0 ) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        int result =  nums[0];
        int temp = result;
        for (int i = 1; i < nums.size(); i++) {
            if (temp > 0) {
                temp += nums[i];
            } else {    
                temp = max( temp, nums[i]);
            }
            result = max(temp, result);
        }
        return result;
        
    }
};
