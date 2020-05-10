/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 * https://leetcode-cn.com/problems/summary-ranges/description/
 * Medium (48.96%)
 * 给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。
 * 示例 1:
 * 输入: [0,1,2,4,5,7]
 * 输出: ["0->2","4->5","7"]
 * 解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。
 * 示例 2:
 * 输入: [0,2,3,4,6,8,9]
 * 输出: ["0","2->4","6","8->9"]
 * 解释: 2,3,4 可组成一个连续的区间; 8,9 可组成一个连续的区间。
 *
 */
class Solution {
   public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;
        string s = to_string(nums[0]);
        if (nums.size() ==1 )  {
            res.push_back(s);
            return res;
        }
        int last = 0;
        for (auto i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                if (i == nums.size() - 1) {
                    s += "->" + to_string(nums[i]);
                    res.push_back(s);
                }
            } else {
                if (i - last != 1) {
                    s += "->" + to_string(nums[i - 1]);
                }

                res.push_back(s);
                s = to_string(nums[i]);
                last = i;

                if (i == nums.size() - 1) {
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};
