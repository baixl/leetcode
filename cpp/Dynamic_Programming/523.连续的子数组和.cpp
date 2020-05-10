/*
 * @lc app=leetcode.cn id=523 lang=cpp
 * [523] 连续的子数组和
 * https://leetcode-cn.com/problems/continuous-subarray-sum/description/
 *
 * Medium (22.03%)
 * 给定一个包含非负数的数组和一个目标整数 k，编写一个函数来判断该数组是否含有连续的子数组，其大小至少为 2，总和为 k
 * 的倍数，即总和为 n*k，其中 n 也是一个整数。
 * 示例 1:
 * 输入: [23,2,4,6,7], k = 6
 * 输出: True
 * 解释: [2,4] 是一个大小为 2 的子数组，并且和为 6。
 * 示例 2:
 * 输入: [23,2,6,4,7], k = 6
 * 输出: True
 * 解释: [23,2,6,4,7]是大小为 5 的子数组，并且和为 42。
 * 说明:
 * 数组的长度不会超过10,000。
 * 你可以认为所有数字总和在 32 位有符号整数范围内。
 */

// @lc code=start
class Solution {
   public:
    /*
    方法1：暴力解法,O(n3)
    方法2: 计算前缀和时间 O(n2) 空间O(n)
        sum[i] 表示nums[0:i]的和，
        在双重循环遍历的时候，nums[i:j]的和 可以用 sum[j] - sum[i] + nums[i] 表示
    */
    bool checkSubarraySum2(vector<int>& nums, int k) {
        if (nums.size() < 0) return false;

        int size = nums.size();
        vector<int> sum_vec(size, 0);  // 前缀后
        sum_vec[0] = nums[0];
        for (auto i = 1; i < size; i++) {
            sum_vec[i] = sum_vec[i - 1] + nums[i];
        }

        for (auto i = 0; i < size - 1; i++) {
            for (auto j = i + 1; j < size; j++) {
                int temp = sum_vec[j] - sum_vec[i] + nums[i];
                if (k == 0) {
                    if (temp == 0) return true;
                } else {
                    if (temp % k == 0) return true;
                }
            }
        }
        return false;
    }
    /*
    方法3: 使用hashmap，
    这个方法是参考leetcode的解法，hashmap存放到nums[i]时的数组和，存入map的val要 取 val%k
    证明：
    假设 nums[0:i]的和为res，假设到j位置，nums[i:j]的和为n*k, 则nums[0:j]的和为 res+ n*k
    (res +n*k)%k == res
    这说明，当后面插入 val%k ， 这个key在map中时，则找到了一个i j 的和是n*k， 直接返回true即可

    */
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        unordered_map<int, int> map;

        int sum = 0;
        map[0] = -1;// 初始设一个0值， 以防[0,0...]这种 
        for (auto i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (k != 0) sum = sum % k;

            if (map.find(sum) != map.end()) {
                if (i - map[sum] > 1) return true;
            } else {
                map[sum] = i;
            }
        }
        return false;
    }
};
// @lc code=end
