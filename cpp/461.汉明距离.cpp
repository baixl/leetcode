/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
给出两个整数 x 和 y，计算它们之间的汉明距离。
注意：
0 ≤ x, y < 231.
示例:
输入: x = 1, y = 4
输出: 2
解释:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
上面的箭头指出了对应二进制位不同的位置。
 */
class Solution {
   public:
    // 异或操作后， 二进制中1的个数(异或： 相等为0， 不相等为1)
    int hammingDistance(int x, int y) {
        int temp = x ^ y;
        if (temp == 0) {
            return 0;
        }
        int result = 0;
        while (temp != 0) {
            if (temp % 2 == 1) {
                result += 1;
            }
            temp = temp / 2;
        }
        return result;
    }
};
