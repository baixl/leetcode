/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 * https://leetcode-cn.com/problems/search-insert-position/description/
 * Easy (44.31%)
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 你可以假设数组中无重复元素。
 * 示例 1:
 * 输入: [1,3,5,6], 5
 * 输出: 2
 *
 */
class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int result = helper(nums, 0, nums.size() -1, target);
        return result;
    }

    int helper(vector<int>& nums, int left, int right, int target) {
        if (left > right) return left;
        int mid = left + (right -left) /2;
        if (nums[mid] == target) {
            return mid;
        } else  if (nums[mid] > target){
            right = mid -1;
        } else {
            left = mid + 1;
        }
        return helper(nums, left, right, target);
    }
};
