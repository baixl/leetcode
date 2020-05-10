/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */
class Solution {
   public:
    /*
    移位操作：
    依次将n的最后一位左移并加到结果上
    */
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int index = 32;
        while (index--) {
            result <<= 1;
            result += n % 2;
            n = n / 2;
        }

        return result;
    }
};
