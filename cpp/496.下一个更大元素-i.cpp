/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 *
 * https://leetcode-cn.com/problems/next-greater-element-i/description/
 *
 * algorithms
 * Easy (60.31%)
 * 给定两个没有重复元素的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2
 * 中的下一个比其大的值。
 *
 * nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出-1。
 *
 * 示例 1:
 *
 *
 * 输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
 * 输出: [-1,3,-1]
 * 解释:
 * ⁠   对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
 * ⁠   对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
 * ⁠   对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。
 * 示例 2:
 * 输入: nums1 = [2,4], nums2 = [1,2,3,4].
 * 输出: [3,-1]
 * 解释:
 * 对于num1中的数字2，第二个数组中的下一个较大数字是3。
 * ⁠   对于num1中的数字4，第二个数组中没有下一个更大的数字，因此输出 -1。
 * 注意:
 * nums1和nums2中所有元素是唯一的。
 * nums1和nums2 的数组大小都不超过1000。
 */
#include <stack>
#include <vector>
class Solution {
   public:
	// 暴力解法
	vector<int> nextGreaterElement1(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		if (nums1.empty() || nums2.empty()) {
			return result;
		}
		unordered_map<int, int> map;
		int max_val = INT_MIN;
		for (int i = 0; i < nums2.size(); i++) {
			map[nums2[i]] = i;
			max_val = max(max_val, nums2[i]);
		}
		for (auto i = 0; i < nums1.size(); i++) {
			if (nums1[i] >= max_val) {
				result.push_back(-1);
			} else {
				int index = map[nums1[i]];
				int flag = false;
				for (auto j = index + 1; j < nums2.size(); j++) {
					if (nums2[j] > nums1[i]) {
						result.push_back(nums2[j]);
						flag = true;
						break;
					}
				}
				if (!flag) {
					result.push_back(-1);
				}
			}
		}
		return result;
	}
	/*
	遍历数组nums2，维护一个单调的栈和hash表
	 */
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		stack<int> s; // 维护一个单调的栈
		unordered_map<int, int> map; // 用于存放数组2中，每个元素对应的下一个更大元素
		for (auto i = 0; i < nums2.size(); i++) {
			while (!s.empty() && s.top() < nums2[i]) {
				map[s.top()] = nums2[i];
				s.pop();
			}
			s.push(nums2[i]);
		}
		vector<int> result(nums1.size(), -1);
		for (auto i = 0; i < nums1.size(); i++) {
			if (map.find(nums1[i]) != map.end()) {
				result[i] = map[nums1[i]];
			} else {
				result[i] = -1;
			}
		}
		return result;
	}
};
