/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用一次。
说明：
所有数字（包括目标数）都是正整数。解集不能包含重复的组合。
示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[[1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]]
示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[[1,2,2],
[5]]
 */
#include <vector>
class Solution {
   public:
    // 回溯：和组合总和1的不同： 1、有重复元素， 2、每个元素在一个组合中只能用一次
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.empty()) {
            return res;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> out;
        vector<int> visited(candidates.size(), 0);  // 剪枝
        backtrack(candidates, target, 0, out, res);
        return res;
    }

    void backtrack(vector<int>& candidates, int target, int start, vector<int>& out, vector<std ::vector<int>>& res) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            res.push_back(out);
            return;
        }
        for (auto i = start; i < candidates.size(); i++) {
            //  剪枝
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            out.push_back(candidates[i]);

            backtrack(candidates, target - candidates[i], i + 1, out, res);
            out.pop_back();
        }
    }
};
