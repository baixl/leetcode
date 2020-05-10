/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode-cn.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (59.28%)
 * Likes:    174
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 示例 1:
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 说明:
 * 你可以假设字符串只包含小写字母。
 * 
 * 进阶:
 * 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */

// @lc code=start
class Solution {
   public:
    // 方法1： hash
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> map; // 最多26个，

        for (auto c : s) {
            map[c] ++;
        }

        for (auto c : t) {
            if (!map.count(c)) return false;
            if (map[c] == 0) return false;
            map[c] --;
        }

        for (auto it = map.begin(); it != map.end(); it++) {
            if (it->second != 0){
                return false;
            }
        }
        return true;
    }
    // 方法2： 先排序
    bool isAnagram2(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
        // int i = 0;
        // while (i < s.size()) {
        //     if (s[i] != t[i]) {
        //         return false;
        //     }
        //     i++;
        // }
        // return true;
    }
};
// @lc code=end

