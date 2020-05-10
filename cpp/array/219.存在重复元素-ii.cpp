/*
 * @lc app=leetcode.cn id=219 lang=cpp
 * [219] 存在重复元素 II
 * https://leetcode-cn.com/problems/contains-duplicate-ii/description/
 * Easy (36.03%)
 * 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j
 * 的差的绝对值最大为 k。
 *
 * 示例 1:
 *
 * 输入: nums = [1,2,3,1], k = 3
 * 输出: true
 *
 * 示例 2:
 *
 * 输入: nums = [1,0,1,1], k = 1
 * 输出: true
 *
 * 示例 3:
 *
 * 输入: nums = [1,2,3,1,2,3], k = 2
 * 输出: false
 *
 */

// @lc code=start
class Solution {
   public:
    /*
    暴力解法，最后一个cae会超时
    */
    bool containsNearbyDuplicate1(vector<int>& nums, int k) {
        for (auto i = 0; i < nums.size(); i++) {
            for (auto j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j] && j - i <= k) return true;
            }
        }
        return false;
    }
    /*
    使用hashmap 缓存之前出现过的数字的位置， 能通过，但空间复杂度较高
    */
    bool containsNearbyDuplicat2(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (auto i = 0; i < nums.size(); i++) {
            int val = nums[i];
            if (map.find(val) != map.end()) {
                if (i - map[val] <= k) return true;
            }
            map[val] = i;
        }
        return false;
    }
    /*
    方法3：使用一个set， set的大小最大为k
    依次遍历nums，发现当前元素出现在set 则直接返回，
    当set大小超过k，则移除i-k的元素
    */
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        for (auto i = 0; i < nums.size(); i++) {
            int val = nums[i];
            if (set.find(val) != set.end()) return true;
            set.insert(val);
            if (set.size() > k) {
                set.erase(nums[i - k]);
            }
        }
        return false;
    }
};
// @lc code=end
