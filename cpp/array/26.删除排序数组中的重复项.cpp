/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return 1;
        int j = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[j] != nums[i]) {
                nums[++j] = nums[i];
            }
        }
        return j + 1;
    }
};
