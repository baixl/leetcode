/*
 * @lc app=leetcode.cn id=377 lang=cpp
 * [377] 组合总和 Ⅳ
 * https://leetcode-cn.com/problems/combination-sum-iv/description/
 *
 * Medium (39.51%)
 * 给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。
 * 示例:
 * nums = [1, 2, 3]
 * target = 4
 * 所有可能的组合为：
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 *
 * 请注意，顺序不同的序列被视作不同的组合。
 *
 * 因此输出为 7。
 * 进阶：
 * 如果给定的数组中含有负数会怎么样？
 * 问题会产生什么变化？
 * 我们需要在题目中添加什么限制来允许负数的出现？
 *
 * 致谢：
 * 特别感谢 @pbrother 添加此问题并创建所有测试用例。
 *
 */

// @lc code=start
class Solution {
   public:
    /*
    方法1 ********************************
    递归搜索 会超时
    */
    int combinationSum41(vector<int>& nums, int target) {
        if (nums.empty() || target <= 0) return 0;
        return backtrace(nums, target);
    }
    // 递归
    int backtrace(vector<int>& nums, int target) {
        if (target == 0) {
            return 1;
        }
        int res = 0;
        for (auto i = 0; i < nums.size(); i++) {
            if (target >= nums[i]) {
                res += backtrace(nums, target - nums[i]);
            }
        }
        return res;
    }

    /*
    方法2********************************
    递归搜索+ 记忆化操作, 还是超时
    */
    unordered_map<int, int> map;
    int combinationSum42(vector<int>& nums, int target) {
        if (nums.empty() || target <= 0) return 0;
        return backtrace2(nums, target);
    }
    // 递归
    int backtrace2(vector<int>& nums, int target) {
        if (map.find(target) != map.end()) {
            return map[target];
        }
        if (target == 0) {
            return 1;
        }
        int res = 0;
        for (auto i = 0; i < nums.size(); i++) {
            if (target >= nums[i]) {
                res += backtrace(nums, target - nums[i]);
            }
        }
        map[target] = res;
        return res;
    }
    /*
    方法2********************************
    动态规划
    */
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.size() < 1) return 0;
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (auto num : nums) {
                if (num <= i) {
                    if (dp[i] > INT_MAX - dp[i - num])  //防止超int范围
                    {
                        dp[i] = 0;  //不要返回0 因为i可能不到target
                                    //但是有组合和为target
                        break;
                    }
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end
