/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 *
 * https://leetcode-cn.com/problems/largest-divisible-subset/description/
 *
 * algorithms
 * Medium (36.38%)
 * Likes:    61
 * Dislikes: 0
 * Total Accepted:    4.6K
 * Total Submissions: 12.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 给出一个由无重复的正整数组成的集合，找出其中最大的整除子集，子集中任意一对 (Si，Sj) 都要满足：Si % Sj = 0 或 Sj % Si =
 * 0。
 * 
 * 如果有多个目标子集，返回其中任何一个均可。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2] (当然, [1,3] 也正确)
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,2,4,8]
 * 输出: [1,2,4,8]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    /*
    动态规划
    假设：序列2、4 构成最大整除子集，则如果下一个数字x是4的倍数， 则x也和这个序列构成最大子集 2、4、x
    则解法为
    1、先排序
    2、动态转移条件 nums[i] % nums[j] == 0 && dp[i] <= dp[j] ==>  dp[i] = dp[j] +1;
    3、难点是记录最大整除子集的序列位置：这里使用一个数组path 来记录 path[i]记录到位置i， 最大整除子集序列，上一个位置的下标
    4、遍历path， 则可以输出最大整除子集序列
    */
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        sort(nums.begin(), nums.end());
        int N = nums.size();
        vector<int> dp(N, 1); // dp 保存为到每个位置为结尾，最大整除子集的大小
        vector<int> path(N, -1); // path path[i]记录到位置i， 最大整除子集序列，上一个位置的下标

        int max_len = 0, end=-1; // max_len 为最大整除子集的长度， end 为最大整除子集，最后位置的下标
        for(auto i = 0; i < N; i++) {
            for( auto j = 0; j <i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] <= dp[j]) {
                    dp[i] = dp[j] +1;
                    path[i] = j;
                }
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
                end  = i;
            }
        } 
        // 回溯 path序列，得到最大整除子集（最终结果）
        vector<int> res;
        for(auto i = end; i != -1; i = path[i]) {
            res.push_back(nums[i]);
        }
        return res;
    }
};
// @lc code=end

