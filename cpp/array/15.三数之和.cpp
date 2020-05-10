/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 * https://leetcode-cn.com/problems/3sum/description/
 * Medium (24.01%)
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组。
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 *
 *
 */
class Solution {
   public:
    // 先排序 后夹逼
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }

        sort(nums.begin(), nums.end());
        const int target = 0;
        for (int left = 0; left < nums.size() - 2; left++) {
            auto mid = left + 1;
            if (mid > 0 && nums[mid] == nums[mid - 1]) continue;
            auto right = nums.size() - 1;
            while (mid < right) {
                int sum_val = nums[left] + nums[mid] + nums[right];
                if (sum_val == target) {
                    vector<int> temp = {nums[left], nums[mid], nums[right]};
                    result.push_back(temp);
                    mid++;
                    right--;
                    while (nums[mid] == nums[mid - 1] && nums[right] == nums[right + 1] && mid < right) {
                        mid++;
                    }
                } else if (sum_val > target) {
                    right--;
                    while (nums[right] == nums[right++] && mid < rigjt) {
                        right--;
                    }

                } else {
                    mid++;
                    while (nums[mid] == nums[mid - 1] && mid < right) {
                        mid++;
                    }
                }
            }
        }
        return result;
    }
};
