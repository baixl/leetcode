/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (29.03%)
 * Total Accepted:    107.6K
 * Total Submissions: 370.7K
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 *
 * 示例 1:
 *
 * 输入: "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 *
 * 示例 2:
 *
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 *
 * 示例 3:
 *
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 *
 */

class Solution {
   public:
   // 方法1 ， 双指针， 保证两个指针之间的部分是目标字串
    int lengthOfLongestSubstring2(string s) {
        if (s.size() == 0) {
            return 0;
        }

        int left = 0, right = 0;
        int max_length = 0;
        set<char> char_set;
        while (right < s.size()) {
            if (char_set.find(s[right]) != char_set.end()) {
                char_set.erase(s[left]);
                left++;
            } else {
                char_set.insert(s[right]);
                right++;
                max_length = max(max_length, right - left);
            }
        }
        return max_length;
    }

    // 方法2：同样是双指针，不过每次重复时都移动左指针， 这个没使用额外的空间
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }

        int left = 0, right = 0;
        int max_length = 0;

        int size = s.size();
        for (right = 0; right < size; right++) {
            for (int k = left; k < right; k++) {
                if (s[k] == s[right]) {
                    left = k + 1;
                    break;
                }
            }
            max_length = max(right - left + 1, max_length);
        }

        return max_length;
    }
};
