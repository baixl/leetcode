/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */
class Solution {
   public:
	int findPeakElement(vector<int>& nums) {
		if (nums.size() == 1) {
			return 0;
		}
		int left = 0, right = nums.size() - 1;
		int mid = 0;
		while (left <= right) {
			mid = left + (right - left) / 2;
			if ((mid == 0 || nums[mid] >= nums[mid - 1]) &&
				(mid == nums.size() - 1 || nums[mid] >= nums[mid + 1])) {
				return mid;
			} else if (mid > 0 && nums[mid - 1] > nums[mid]) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		return mid;
	}
};
