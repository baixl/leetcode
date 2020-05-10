/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 *
 * https://leetcode-cn.com/problems/majority-element-ii/description/
 * Medium (41.99%)
 * 给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
 * 说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。
 * 示例 1:
 *
 * 输入: [3,2,3]
 * 输出: [3]
 *
 * 示例 2:
 *
 * 输入: [1,1,1,3,3,2,2,2]
 * 输出: [1,2]
 *
 */
class Solution {
   public:
    /*
    摩尔投票法的升级版本
    超过n/3的数最多只能有两个。先选出两个候选人A,B。 遍历数组，分三种情况：
    1.如果投A（当前元素等于A），则A的票数++;
    2.如果投B（当前元素等于B），B的票数++；
    3.如果A,B都不投（即当前与A，B都不相等）,那么检查此时A或B的票数是否减为0：
    3.1 如果为0,则当前元素成为新的候选人；
    3.2 如果A,B两个人的票数都不为0，那么A,B两个候选人的票数均减一；
    遍历结束后选出了两个候选人，但是这两个候选人是否满足>n/3，还需要再遍历一遍数组，找出两个候选人的具体票数。


    */
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if (nums.size() < 1) return nums;
        int candiate1 = 0, cnt1 = 0, candiate2 = 0, cnt2 = 0;
        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] == candiate1) {
                cnt1++;
            } else if (nums[i] == candiate2) {
                cnt2++;
            } else if (cnt1 == 0) {  // 没有候选
                candiate1 = nums[i];
                cnt1++;
            } else if (cnt2 == 0) {
                candiate2 = nums[i];
                cnt2++;
            } else {  // 既不是候选1 也不是候选2
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for (auto num : nums) {
            if (num == candiate1)
                ++cnt1;
            else if (num == candiate2)
                ++cnt2;
        }
        if (cnt1 > nums.size() / 3) res.push_back(candiate1);
        if (cnt2 > nums.size() / 3) res.push_back(candiate2);
        return res;
    }
};
