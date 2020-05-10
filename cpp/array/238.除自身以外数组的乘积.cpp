/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 *
 * https://leetcode-cn.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (67.47%)
\ * Likes:    359
 * Dislikes: 0
 * Total Accepted:    34.8K
 * Total Submissions: 51.6K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i]
 * 之外其余各元素的乘积。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [1,2,3,4]
 * 输出: [24,12,8,6]
 * 
 * 
 * 
 * 提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。
 * 
 * 说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
 * 
 * 进阶：
 * 你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
 * 
 */

// @lc code=start
class Solution {
   public:
    /*
    方法1 左积 右积
    时间复杂度 O(3n) ==> O(n)。 空间 O(2n) ==> O(n)
    */
    vector<int> productExceptSelf2(vector<int>& nums) {
        vector<int> result;
        if (nums.empty()) {
            return result;
        }
        int size = nums.size();
        vector<int> v_left(size, 1), v_right(size, 1);
        for (auto i = 1; i < nums.size(); i++) {
            v_left[i] = v_left[i - 1] * nums[i - 1];
        }
        for (auto i = size - 2; i >= 0; i--) {
            v_right[i] = v_right[i + 1] * nums[i + 1];
        }
        for (auto i = 0; i < size; i++) {
            result.push_back(v_left[i] * v_right[i]);
        }
        return result;
    }
    /*
   方法2 左积 右积
   时间复杂度 O(3n) ==> O(n)。 空间 O(1)
   */
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 1);
        if (nums.empty()) {
            return result;
        }
        int left = 1, right = 1;
        for (auto i = 0; i < size; i++) {
            result[i] *= left;
            left *= nums[i];

            result[size - i - 1] *= right;
            right = right * nums[size - i - 1];
        }
        return result;
    }
};
// @lc code=end

