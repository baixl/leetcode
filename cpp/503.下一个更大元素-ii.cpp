/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 *
 * https://leetcode-cn.com/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (48.97%)
 * 给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x
 * 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出-1。
 * 示例 1:
 *
 * 输入: [1,2,1]
 * 输出: [2,-1,2]
 * 解释: 第一个 1 的下一个更大的数是 2；
 * 数字 2 找不到下一个更大的数；
 * 第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
 *
 * 注意: 输入数组的长度不会超过 10000。
 *
 */
class Solution {
   public:
    // 数组循环的处理：将数组复制一倍， 则将循环问题转为一个非循环的数组了， 然后借鉴 下一个更大的元素1 的解法
    // 当然：可以先构造出这个循环的数组
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(), -1);
        vector<int> new_vector(nums);
        for (auto i = 0; i < nums.size(); i++) {
            new_vector.push_back(nums[i]);
        }

        stack<int> s;
        for (auto i = 0; i < new_vector.size(); i++) {
            while (!s.empty() && new_vector[i] > new_vector[s.top()]) {
                result[s.top()] = new_vector[i];
                s.pop();
            }
            if (i < nums.size()) {
                s.push(i);  // 将下标入栈
            }
        }

        return result;
    }
};
