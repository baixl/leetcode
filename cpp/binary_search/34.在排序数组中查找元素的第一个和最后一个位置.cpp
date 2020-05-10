/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        if (nums.empty()) {
            return {-1, -1};
        }
        int left = 0, right = nums.size() - 1;
        int mid = left + (right - left) / 2;
        int left_index = search_left(nums, left, right, target);
        int right_index = search_right(nums, left, right, target);
        if (left_index == -1 || right_index == -1) {
            result.push_back(-1);
            result.push_back(-1);
        } else {
            result.push_back(left_index);
            result.push_back(right_index);
        }
        return result;
    }
    // 查到与目标数相等的最左下标
    int search_left(vector<int>& nums, int left, int right, int target) {
        if (left > right) {
            return -1;
        }
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) {
            return search_left(nums, left, mid - 1, target);
        } else if (nums[mid] < target) {
            return search_left(nums, mid + 1, right, target);
        } else {
            if (mid - 1 >= 0 && nums[mid - 1] == target) {
                return search_left(nums, left, mid - 1, target);
            }
            return mid;
        }
    }

    // 查到与目标数相等的最右边下标
    int search_right(vector<int>& nums, int left, int right, int target) {
        if (left > right) {
            return -1;
        }
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) {
            return search_right(nums, left, mid - 1, target);
        } else if (nums[mid] < target) {
            return search_right(nums, mid + 1, right, target);
        } else {
            if (mid + 1 <= right && nums[mid + 1] == target) {
                return search_right(nums, mid + 1, right, target);
            }
            return mid;
        }
    }
};
