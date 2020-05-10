/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]
 */
class Solution {
   public:
    /*
    回朔法：
    */
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        if (s.empty()) return result;
        vector<string> cur_vec;
        dfs(s, result, cur_vec, 0);

        return result;
    }

    void dfs(string& s, vector<vector<string>>& result, vector<string>& cur_vec, int start) {
        if (start == s.size()) {  //回溯退出条件
            result.push_back(cur_vec);
            return;
        }
        for (auto i = start; i < s.size(); i++) {
            if (is_huiwen(s, start, i)) {
                string sub_str = s.substr(start, i - start + 1);
                cur_vec.push_back(sub_str);
                dfs(s, result, cur_vec, i + 1);
                cur_vec.pop_back();
            }
        }
    }
    bool is_huiwen(string& s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
