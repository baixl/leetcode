/*
 * @lc app=leetcode.cn id=49 lang=cpp
 * [49] 字母异位词分组
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * Medium (58.70%)
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 示例:
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 *
 * 说明：
 *
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 *
 */

// @lc code=start
class Solution {
   public:
   /*
   解法： 排序 + hash
   */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {};
        unordered_map<string, vector<string>> map;
        for (auto s : strs) {
            string ori = s;
            sort(ori.begin(), ori.end());
            map[ori].push_back(s);
        }
        vector<vector<string>> res;
        auto it = map.begin();
        while (it != map.end()) {
            res.push_back(it->second);
            it++;
        }
        return res;
    }
};
// @lc code=end
