/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 * Easy (60.27%)
 * 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 *
 * 你可以假设数组是非空的，并且给定的数组总是存在众数。
 *
 * 示例 1:
 *
 * 输入: [3,2,3]
 * 输出: 3
 *
 * 示例 2:
 *
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 *
 *
 */
class Solution {
   public:
    // 方法1： hash
    int majorityElement1(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        unordered_map<int, int> map;
        for (auto& num : nums) {
            if (map.find(num) != map.end()) {
                map[num]++;
                if (map[num] > nums.size() / 2) {
                    return num;
                }
            } else {
                map[num] = 1;
            }
        }
        return -1;
    }

    // 方法2： 排序， 直接返回数组中间的那个数
    int majorityElement2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
    // 方法3：摩尔投票法 from leetcode
    /*
    解法三：摩尔投票法
    找数组中超过一半的数字，这意味着数组中其他数字出现次数的总和都是比不上这个数字出现的次数 。
    即如果把 该众数记为 +1 ，把其他数记为 −1 ，将它们全部加起来，和是大于 0 的。
    所以可以这样操作：

    设置两个变量 candidate 和 count，candidate 用来保存数组中遍历到的某个数字，count 表示当前数字的出现次数，
    1、初始化：candidate 保存为数组中的第一个数字，count 为 1
    2、遍历整个数组 如果数字与之前 candidate 保存的数字相同，则 count 加 1
    3、如果数字与之前 candidate 保存的数字不同，则 count 减 1
    4、如果出现次数 count 变为 0 ，candidate 进行变化，保存为当前遍历的那个数字，并且同时把 count 重置为 1
    遍历完数组中的所有数字即可得到结果
    */
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int candiate = nums[0], count = 1;
        for (auto i = 1; i < nums.size(); i++) {
            if (nums[i] == candiate)
                count++;
            else 
                count --;
            if (count == 0) {
                candiate = nums[i];
                count = 1;
            }
        }

        return candiate;
    }
};
