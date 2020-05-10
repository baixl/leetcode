/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 *
 * https://leetcode-cn.com/problems/next-greater-element-iii/description/
 *
 * Medium (27.51%)
 * 给定一个32位正整数 n，你需要找到最小的32位整数，其与 n 中存在的位数完全相同，并且其值大于n。如果不存在这样的32位整数，则返回-1。
 * 示例 1:
 * 输入: 12
 * 输出: 21
 * 示例 2:
 * 输入: 21
 * 输出: -1
 */

// @lc code=start
class Solution {
   public:
    // 12 ==> "12" 字符串下一个更大的元素是"21"
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.size() - 2;
        while (i >= 0 && s[i + 1] <= s[i]) {  // 找到第一个增序开始的位置，右边是降序部分
            i--;
        }
        if (i < 0) return -1;  // 完全降序的数组，无法形成一个更大的数

        int j = s.size() - 1;
        while (j >= 0 && s[j] <= s[i]) {  // 找到比刚才第一个增序位置大的结果
            j--;
        }
        swap(s, i, j);
        reverse(s, i + 1);
        long res = stol(s);
        if (res > INT_MAX) {
            return -1;
        } else {
            return res;
        }
    }

    void reverse(string& s, int start) {
        int i = start, j = s.size() - 1;
        while (i < j) {
            swap(s, i, j);
            i++;
            j--;
        }
    }

    void swap(string& s, int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
};
// @lc code=end
