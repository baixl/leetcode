/*
 * [371] 两整数之和
 不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b
​​​​​​​之和。 示例 1: 输入: a = 1, b = 2 输出: 3 示例 2:

输入: a = -2, b = 3
输出: 1
 */
class Solution {
   public:
    /*
    c = a ^ b得到不包括进位的和
    d = a & b得到哪些是进位
    当d不为0时，只要再计算c与(d<<1)的和即可
    */
    int getSum(int a, int b) {
        int c = a ^ b;
        unsigned int d = a & b;
        if (d != 0) {
            //说明存在进位
            d <<= 1;
            return getSum(c, d);
        } else
            return c;
    }
};
