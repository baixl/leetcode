/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 *
 * https://leetcode-cn.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (60.37%)
 * Likes:    553
 * Dislikes: 0
 * Total Accepted:    130.8K
 * Total Submissions: 216.7K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 * 
 * 说明:
 * 
 * 
 * 必须在原数组上操作，不能拷贝额外的数组。
 * 尽量减少操作次数。
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    // 两指针滑动即可
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return;
        }
        int i = 0, j = 0;
        while (j < size) {
            if (nums[j] == 0) {
                j++;
            } else {
                nums[i] = nums[j];
                i++;
                j++;
            }
        }
        while (i < j) {
            nums[i] = 0;
            i++;
        }
        return;
    }
};
// @lc code=end

