/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 * https://leetcode-cn.com/problems/3sum-closest/description/
 * Medium (41.67%)
 * Testcase Example:  '[-1,2,1,-4]\n1'
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 *
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 *
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

 */
class Solution {
   public:
    /*
    先排序 后夹逼
    和三数之和类似，
    1、定义三个坐标 left  mid right， left=0, mid = left+1, right =size() -1;
    2、遍历时， left从0开始，mid从 left+1开始， right =size()-1 固定不动
    3、sum_val= nums[left] +nums[mid] + nums[right]
    4、记录min_gap  =  abs(sum_val -target) 为最小的差值时的三数之后
    5、若未变小有两种情况：
    若sum_val >target:说明现在的三数之和大了，要变小，则right向左移动
    若sum_val < target: 说明三数之和小了，要变大，mid向右移动
    */
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int result = INT_MAX;
        int min_gap = INT_MAX;
        for (auto left = 0; left < nums.size() - 2; left++) {
            auto mid = left + 1;
            // if (left > 0 && nums[left] == nums[left - 1]) continue;
            auto right = nums.size() - 1;
            while (mid < right) {
                int sum_val = nums[left] + nums[mid] + nums[right];
                int temp = abs(target - sum_val);
                if (temp < min_gap) {
                    min_gap = temp;
                    result = sum_val;
                } else if (sum_val > target) {
                    right--;
                } else {
                    mid++;
                }
            }
        }
        return result;
    }
};
