/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.36%)
 * Likes:    640
 * Dislikes: 0
 * Total Accepted:    105.9K
 * Total Submissions: 308.2K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 *
 * 如果不存在公共前缀，返回空字符串 ""。
 *
 * 示例 1:
 *
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 *
 *
 * 示例 2:
 *
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 *
 *
 * 说明:
 *
 * 所有输入只包含小写字母 a-z 。
 *
 */
class Solution {
   public:
    /*
    1、若str为空，直接返回
    2、取第一个字符串，
    3、遍历后面的字符串， 一次和第一个比较，依次取公共子串， 直到 结果为空
    */
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        if (strs.empty()) {
            return result;
        }
        result = strs[0];
        for (auto i = 1; i < strs.size(); i++) {
            int j = 0;
            for (; j < result.size() && j < strs[i].size(); j++) {
                if (result[j] != strs[i][j]) {
                    break;
                }
            }
            result = result.substr(0, j);
            if (result.empty()) {
                return result;
            }
        }
        return result;
    }
    // 方法2： 暴力，先找到最短的长度，然后依次遍历
    string longestCommonPrefix2(vector<string>& strs) {
        string result = "";
        if (strs.empty()) {
            return result;
        }

        int min_length = INT_MAX;
        int min_index = -1;
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].size() < min_length) {
                min_length = strs[i].size();
                min_index = i;
            }
        }

        string min_str = strs[min_index];
        for (int i = 0; i < min_length; i++) {
            for (auto s : strs) {
                if (s[i] != min_str[i]) {
                    return result;
                }
            }
            result.push_back(min_str[i]);
        }
        return result;
    }
};
