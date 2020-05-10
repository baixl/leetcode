/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 *
 * https://leetcode-cn.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (54.70%)
 * Likes:    388
 * Dislikes: 0
 * Total Accepted:    71.3K
 * Total Submissions: 130.4K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 * 
 * 注意:
 * 不能使用代码库中的排序函数来解决这道题。
 * 
 * 示例:
 * 
 * 输入: [2,0,2,1,1,0]
 * 输出: [0,0,1,1,2,2]
 * 
 * 进阶：
 * 
 * 
 * 一个直观的解决方案是使用计数排序的两趟扫描算法。
 * 首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    //双指针
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        int left = 0, right = nums.size()-1;
        for (auto i = 0; i <= right; i++) {
            if (nums[i] == 0) {
                swap(nums[left], nums[i]);
                left++; // 从左往右，最开始 i 和left一定相等， 交换一定是 0、1交换
            } else if (nums[i] == 2) {
                swap(nums[right], nums[i]);
                right--;
                i--;  // 替换后，当前位置还需要check一次， 因为不知道当前交换的是什么元素
            }
        }
    }
};
// @lc code=end

