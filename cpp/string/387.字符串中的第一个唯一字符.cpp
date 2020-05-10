/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */
class Solution {
   public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;

        for (auto c : s) {
            if (map.find(c) != map.end()) {
                map[c] += 1;
            } else {
                map[c] = 1;
            }
        }

        int result = -1;
        for (int i = 0; i < s.size(); i++) {
            if (map[s[i]] == 1) {
                result = i;
                return result;
            }
        }
        return result;
    }
};
