/*
[4] 寻找两个有序数组的中位数
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))
你可以假设 nums1 和 nums2 不会同时为空。
示例 1:
nums1 = [1, 3]
nums2 = [2]
则中位数是 2.0
示例 2:
nums1 = [1, 2]
nums2 = [3, 4]
则中位数是 (2 + 3)/2 = 2.5
 */
#include <vector>
class Solution {
   public:
	/*
	方法2、因为两个数组是有序的，所以用二分查找。 分治法
	思想： 初步排序中位数不可能的区间，指导找到中位数
	假设nums1的中位数未mid1， nums2的中位数为mid2，
	若mid1 < mid2: 则整体中位数只能出现在mid1的右侧和 mid2的左侧
	若mid1 > mid2: 则整体中位数只能出现在mid1的左侧和 mid2的右侧
	 */
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		//todo:
	}
	/*
	方法1、暴力求解， 直接归并排序，然后求数组的中间位置的算法, 空间： O(n) 时间：O(m+n)
	 */
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> temp_vec;
		auto i = 0, j = 0;
		while (i < nums1.size() && j < nums2.size()) {
			if (nums1[i] < nums2[j]) {
				temp_vec.push_back(nums1[i]);
				i++;
			} else {
				temp_vec.push_back(nums2[j]);
				j++;
			}
		}
		while (i < nums1.size()) {
			temp_vec.push_back(nums1[i]);
			i++;
		}
		while (j < nums2.size()) {
			temp_vec.push_back(nums2[j]);
			j++;
		}

		int size = temp_vec.size();
		cout << size << endl;
		if (size % 2 == 1) {
			return temp_vec[size / 2];
		} else {
			return (temp_vec[size / 2 - 1] + temp_vec[size / 2]) / 2.0;
		}
	}
};
