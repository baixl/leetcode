/*
 * @lc app=leetcode.cn id=220 lang=cpp
 * [220] 存在重复元素 III
 * https://leetcode-cn.com/problems/contains-duplicate-iii/description/
 * Medium (24.87%)
 * 给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值最大为 t，并且 i 和 j
 * 之间的差的绝对值最大为 ķ。
 *
 * 示例 1:
 * 输入: nums = [1,2,3,1], k = 3, t = 0
 * 输出: true
 * 示例 2:
 * 输入: nums = [1,0,1,1], k = 1, t = 2
 * 输出: true
 * 示例 3:
 *
 * 输入: nums = [1,5,9,1,5,9], k = 2, t = 3
 * 输出: false
 *
 */

// @lc code=start
class Solution {
   public:
    /*
    解决这个问题需要找到一组满足以下条件的 i 和 j：
    1、|i - j| <=k
    2、| nums[i| - nums[j] | <= t
    方法1： 维护一个滑动窗口k， 这种情况下，条件1 满足，只需要找到满足条件2的结构即可
    最后一个case 超时
    */
    bool containsNearbyAlmostDuplicate1(vector<int>& nums, int k, int t) {
        for (auto i = 0; i < nums.size(); i++) {
            for (auto j = max(i - k, 0); j < i; j++) {
                long val = long(nums[i]) - long(nums[j]);
                if (abs(val) <= long(t)) return true;
            }
        }
        return false;
    }
    /*
   方法2：
    */
    bool containsNearbyAlmostDuplicate2(vector<int>& nums, int k, int t) {
    //    todo
    }
};
// @lc code=end
