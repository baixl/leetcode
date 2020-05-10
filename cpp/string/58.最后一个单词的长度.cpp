/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * Easy (31.41%)
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
 * 如果不存在最后一个单词，请返回 0 。
 * 说明：一个单词是指由字母组成，但不包含任何空格的字符串。
 * 示例:
 * 输入: "Hello World"
 * 输出: 5
 */

// @lc code=start
class Solution {
   public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int res = 0;
        int j = s.size() - 1;
        while (s[j] == ' ') {  // 从最后一个非空格开始计算
            j--;
        }
        if (j < 0) return 0;
        while (j >= 0 && s[j] != ' ') {
            res++;
            j--;
        }

        return res;
    }
};
// @lc code=end
