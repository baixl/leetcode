/*
 * @lc app=leetcode.cn id=209 lang=cpp
 Medium (39.59%)
 * [209] 长度最小的子数组
 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s
的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。 示例:
输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
进阶:
如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
 */
class Solution {
   public:
    /*
    方法1 滑动窗口解法：
    定义两个指针 i j, nums[i:j] 相当于一个滑动窗口， 统计nums[i:j] 和，
    如果和小于目标值s，则j向右滑动，如果大于s，则i向右滑动
    直到i到数组右侧
    时间O(n)
    */
    int minSubArrayLen1(int s, vector<int>& nums) {
        int left = 0, right = 0;
        int result = INT_MAX;
        int sum = 0;
        while (left < nums.size()) {
            if (right < nums.size() && sum < s) {
                sum += nums[right];
                right++;
            } else {
                sum -= nums[left];
                left++;
            }
            if (sum >= s) {
                result = min(result, right - left);
            }
        }
        if (result == INT_MAX) {  // 不存在
            result = 0;
        }
        return result;
    }

    /*
    二分查找： 用一个数组sum[i] 保存前i-1个数的和。 这个数组sum是递增的。
    然后从一个位置用二分查找 大于 sum[i] +s 的值，这样可以保证 sum[i] 到 sum[i] +s 区间的和是>=s的， 同时
    抛弃了前i-1位数的和
    */
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> sum(nums.size() + 1, 0);  // sum[i] 保存到i-1位置数组的和
        for (auto i = 1; i <= nums.size(); i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        int result = INT_MAX;
        for (auto i = 0; i < nums.size(); i++) {
            int pos = binary_search(i + 1, nums.size(), sum, sum[i] + s);  // 找到则保证该区间的值是>=s
            if (pos == nums.size() + 1) continue;
            result = min(result, pos - i);
        }
        if (result == INT_MAX) {
            result = 0;
        }
        return result;
    }
    // 二分查找 > sum[i] +s 的位置
    int binary_search(int left, int right, vector<int>& sum, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (sum[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
