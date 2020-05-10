/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 *
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 * Hard (45.09%)
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * ( 例如，数组 [0,1,2,4,5,6,7]  可能变为 [4,5,6,7,0,1,2] )。
 * 请找出其中最小的元素。
 * 注意数组中可能存在重复的元素。
 * 示例 1：
 * 输入: [1,3,5]
 * 输出: 1
 * 示例 2：
 *
 * 输入: [2,2,2,0,1]
 * 输出: 07
 *
 * 说明：
 *
 * 这道题是 寻找旋转排序数组中的最小值 的延伸题目。
 * 允许重复会影响算法的时间复杂度吗？会如何影响，为什么？
 */
class Solution {
   public:
    // 二分搜索 相似题目：33
    /* 1、mid 节点和右侧节点比较
    比153题难得地方在于， 现在数组中有重复元素
    依次比较nums[mid] 和nums[right]
    如果 nums[mid] > nums[right]  最小值一定在右侧， ==> left = mid+1
    如果 nums[mid] < nums[right]  最小值一定在左侧(可能就是mid点)， ==> right = mid
    如果 nums[mid] == nums[right]  (难点) 此时无法判断最小值在左右那个区间，， 只需将right 向左移动即可
     */
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        return binary_search(nums, 0, nums.size() - 1);
    }
    int binary_search(vector<int>& nums, int left, int right) {
        if (left >= right) return nums[left];
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid+1;
        } else if (nums[mid] < nums[right]) {
            right = mid;
        } else {
            right = right - 1;
        }
        return binary_search(nums, left, right);
    }
};
