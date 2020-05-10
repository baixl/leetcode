/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 *
 * https://leetcode-cn.com/problems/third-maximum-number/description/
 *
 * Easy (32.77%)
 * 给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
 * 示例 1:
 * 输入: [3, 2, 1]
 * 输出: 1
 *
 * 解释: 第三大的数是 1.
 *
 * 示例 2:
 *
 * 输入: [1, 2]
 *
 * 输出: 2
 * 解释: 第三大的数不存在, 所以返回最大的数 2 .
 *
 * 示例 3:
 *
 * 输入: [2, 2, 3, 1]
 * 输出: 1
 * 解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
 * 存在两个值为2的数，它们都排第二。
 *
 *
 */
class Solution {
   public:
    /*
    方法1： 定义3个数，遍历3遍数组，依次求最大值，第2大值，第3大值
    */
    int thirdMax(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        int max1 = INT_MIN, max2 = max1, max3 = max1, cnt = 0;
        for (auto i = 0; i < nums.size(); i++) {
            max1 = max(max1, nums[i]);
        }
        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] != max1) {
                max2 = max(nums[i], max2);
            }
        }
        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] != max1 && nums[i] != max2) {
                max3 = max(nums[i], max3);
                cnt++;
            }
        }
        return cnt > 0 ? max3 : max1;
    }
};
