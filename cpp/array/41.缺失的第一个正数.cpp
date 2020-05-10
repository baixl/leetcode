/*
 * @lc app=leetcode.cn id=41 lang=cpp
 * [41] 缺失的第一个正数
 * https://leetcode-cn.com/problems/first-missing-positive/description/
 * Hard (36.45%)
 * 给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
 * 示例 1:
 * 输入: [1,2,0]
 * 输出: 3
 * 示例 2:
 * 输入: [3,4,-1,1]
 * 输出: 2
 * 示例 3:
 * 输入: [7,8,9,11,12]
 * 输出: 1
 * 说明:
 *
 * 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
 *
 */
class Solution {
   public:
    //  非常数空间的做法
    /*
    要求常数空间，和O(n)时间。则不能对数组排序， 不能使用额外的空间 比如hash 数组等
    这里考虑 若数据排序后应该是[123...n]这样, 所以需要对数组进行排序， 这里将nums[i] =val
    与 nums[val-1](下标是val-1)的数字交换，如果val-1 超出数组的下标范围，则跳过。
    最终check数组是否满足 nums[i] = nums[i+1]
    */
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() <= 0) return 1;
        int size = nums.size();
        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] > 0 && nums[i] <= size && nums[i] != nums[nums[i] - 1]) {
                int temp = nums[i];
                nums[i] = nums[temp - 1];
                nums[temp - 1] = temp;
                i--;
            } else {
                continue;
            }
        }
        for (auto i = 0; i < size; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return size + 1;
    }

    //  非常数空间的做法
    int firstMissingPositive2(vector<int>& nums) {
        if (nums.empty()) return 1;
        sort(nums.begin(), nums.end());
        int index = 1;
        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] > index) {
                return index;
            } else if (nums[i] < index) {
                continue;
            } else {
                index++;
            }
        }

        return index;
    }
};
