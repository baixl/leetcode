/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为
(i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2。
图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

示例:
输入: [1,8,6,2,5,4,8,3,7]
输出: 49
 */
class Solution {
   public:
	/*
	容器中盛放水的最大值依赖最短的垂线。
	给定双指针，left 指向数组开始， right 指向数组末尾
	一开始先移动较短垂线一边的指针， 因为如果移动较长的指针，
	容器盛放水的最大值，还是受限于最短的一边
	 */
	int maxArea(vector<int>& height) {
		if (height.size() <= 1) {
			return 0;
		}
		int left = 0, right = height.size() - 1;
		int max_area = INT_MIN;
		while (left <= right) {
			int temp = (right - left) * min(height[left], height[right]);
			max_area = max(max_area, temp);
			if (height[right] > height[left]) {
				left++;
			} else {
				// int temp = (right - left) * min(height[left], height[right]);
				// max_area = max(max_area, temp);
				right--;
			}
		}
		return max_area;
	}
};
