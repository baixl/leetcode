/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
你可以假设数组中不存在重复的元素。
你的算法时间复杂度必须是 O(log n) 级别。
示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
 */
#include <vector>

class Solution {
   public:
	 /* 解题思路：
	  二分查找的变体，首先判断mid和target是否相等
	  1 相等，返回下标
	  2 mid比nums[right] 小，说明从mid到right是升序的，判断target是否在这个区间
	  3 mid比nums[right] 大，说明从left到mid是升序的，判断target是否在这个区间
	*/
	int search(vector<int>& nums, int target) {
		if (nums.size() <= 0) {
			return -1;
		}

		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			if (nums[mid] < nums[right]) {// 从mid 到right 是升序的
				if (target > nums[mid] && target <= nums[right]) {
					left = mid+1;
				} else {
					right =  mid-1;
				}
			} else { // 从 left 到mid 是升序的
				if (target >= nums[left] && target < nums[mid]) {
					right = mid -1;
				} else {
					left = mid + 1;
				}   
			}
		}
		return -1;
	}
};
