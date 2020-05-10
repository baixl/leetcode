/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 *
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/description/
 * Medium (49.54%)
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * ( 例如，数组 [0,1,2,4,5,6,7]  可能变为 [4,5,6,7,0,1,2] )。
 * 请找出其中最小的元素。
 * 你可以假设数组中不存在重复元素。
 * 示例 1:
 * 输入: [3,4,5,1,2]
 * 输出: 1
 * 示例 2:
 * 输入: [4,5,6,7,0,1,2]
 * 输出: 0
 *
 */
class Solution {
   public:
    // 二分搜索 相似题目：33
    /* 1、mid 节点和右侧节点比较 ， 
    若 nums[mid] > nums[right]: 则最小值一定在右侧半段，
    若 nums[mid] < nums[right]: 则最小值一定在左侧半段， 可能包含mid节点

    */
    int findMin(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        return binary_search(nums, 0, nums.size() - 1);
    }
    int binary_search(vector<int>& nums, int left, int right) {
        if (left >= right)  return nums[left];
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else  {
            right = mid;
        }
        return binary_search(nums, left, right);
    }
};
