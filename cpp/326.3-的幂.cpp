/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 给定一个整数，写一个函数来判断它是否是 3 的幂次方。

示例 1:
 */
class Solution {
   public:
    bool isPowerOfThree(int n) {
        if (n<=0) return false;
        int result = 0;
        while (n > 1) {
            if (n %3 !=0) {
                return false;
            }
            n = n / 3;
        }
        return n == 1;
    }
};
