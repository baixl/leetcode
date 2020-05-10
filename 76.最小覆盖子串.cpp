/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (35.54%)
 * Likes:    408
 * Dislikes: 0
 * Total Accepted:    31.9K
 * Total Submissions: 89.6K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T
 * 所有字母的最小子串。
 *
 * 示例：
 *
 * 输入: S = "ADOBECODEBANC", T = "ABC"
 * 输出: "BANC"
 *
 * 说明：
 *
 *
 * 如果 S 中不存这样的子串，则返回空字符串 ""。
 * 如果 S 中存在这样的子串，我们保证它是唯一的答案。
 *
 *
 */

// @lc code=start
class Solution {
   public:
    /***************************************************
     * 方法4： 滑动窗口，双指针
     * https://leetcode-cn.com/problems/minimum-window-substring/solution/hua-dong-chuang-kou-suan-fa-tong-yong-si-xiang-by-/
     ***************************************************/

    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        int start = 0, min_len = INT_MAX;
        int left = 0, right = 0;
        unordered_map<char, int> win_map;  // 滑动窗口下字符的计算
        unordered_map<char, int> t_map;    // t字符串对应的map

        for (char c : t) t_map[c]++;
        int match = 0;
        while (right < s.size()) {
            char c = s[right];
            if (t_map.count(c)) {
                win_map[c]++;
                if (win_map[c] == t_map[c]) {
                    match++;
                }
            }
            right++;
            while (match == t_map.size()) {
                if (right - left < min_len) {
                    min_len = right - left;
                    start = left;
                }
                char c1 = s[left];
                if (t_map.count(c1)) {
                    win_map[c1]--;
                    if (win_map[c1] < t_map[c1]) match--;
                }
                left++;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};
// @lc code=end
