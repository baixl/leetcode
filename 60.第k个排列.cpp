/*
 * @lc app=leetcode.cn id=60 lang=cpp
 * [60] 第k个排列
 * https://leetcode-cn.com/problems/permutation-sequence/description/
 * algorithms
 * Medium (48.40%)
 * 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
 * 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 给定 n 和 k，返回第 k 个排列。
 * 说明：
 * 给定 n 的范围是 [1, 9]。
 * 给定 k 的范围是[1,  n!]。
 *
 * 示例 1:
 * 输入: n = 3, k = 3
 * 输出: "213"
 *
 *
 * 示例 2:
 *
 * 输入: n = 4, k = 9
 * 输出: "2314"
 *
 *
 */

// @lc code=start
class Solution {
   public:
    // 方法1:********************************
    //
    string getPermutation(int n, int k) {}

    // 方法2:********************************
    //  直接调用next_pert_permutation
    string getPermutation2(int n, int k) {
        string s = string("123456789").substr(0, n);
        for (auto i = 1; i < k; i++) {
            next_permutation(s.begin(), s.end());
        }
        return s;
    }
};
// @lc code=end
