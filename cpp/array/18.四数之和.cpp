/*
 * @lc app=leetcode.cn id=18 lang=cpp
 * [18] 四数之和
 * https://leetcode-cn.com/problems/4sum/description/
 * Medium (35.91%)
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 注意：
 * 答案中不可以包含重复的四元组。
 * 示例：
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 *
 *
 */
class Solution {
   public:
    // 先排序， 后夹逼
    // 固定两个位置， 依次变化另外两个位置，复用两数之和
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        for (auto i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (auto j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    int sum_val = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum_val < target) {
                        left++;
                    } else if (sum_val > target) {
                        right--;
                    } else {
                        vector<int> temp_vec = {nums[i], nums[j], nums[left], nums[right]};
                        result.push_back(temp_vec);
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1]) {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right + 1]) {
                            right--;
                        }
                    }
                }
            }
        }
        return result;
    }
};
