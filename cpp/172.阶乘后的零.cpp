/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 给定一个整数 n，返回 n! 结果尾数中零的数量。

示例 1:
输入: 3
输出: 0
解释: 3! = 6, 尾数中没有零。
示例 2:

输入: 5
输出: 1
解释: 5! = 120, 尾数中有 1 个零.
说明: 你算法的时间复杂度应为 O(log n) 。
 */
class Solution {
   public:
    /*
    要想阶乘末尾是0， 则必须包含 5 * 2 (因子中5的数量)
    只要需要对数字按照/5 取其中包含的5的数量
    */
    int trailingZeroes(int n) {
        int result = 0;
        if (n < 5) {
            return result;
        }
        while (n >= 5) {
            int new_val = n / 5;
            n = new_val;
            result += new_val;
        }
        return result;
    }
};
