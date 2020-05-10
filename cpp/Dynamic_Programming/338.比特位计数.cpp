/*
 * [338] 比特位计数
 * https://leetcode-cn.com/problems/counting-bits/description/
 *
 * 相关题目：https://leetcode-cn.com/problems/number-of-1-bits/  二进制中1的个数
 *
 * algorithms
 * Medium (72.96%)

 * 给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。
 * 示例 1:
 * 输入: 2
 * 输出: [0,1,1]
 * 示例 2:
 * 输入: 5
 * 输出: [0,1,1,2,1,2]
 * 进阶:
 * 给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？
 * 要求算法的空间复杂度为O(n)。
 * 你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。
 */
class Solution {
   public:
    // 方法1： 暴力解法， 依次求各个数字的二进制中1 的个数
    //计算数字num的二进制中1的个数
    int count_one(int num) {
        if (num <= 0) {
            return 0;
        }
        int res = 0;
        int mask = 1;
        while (num > 0) {
            // if (num % 2 == 1) { 或者
            if (num & mask == 1) {
                res += 1;
            }
            num >>= 1;
        }
        return res;
    }
    vector<int> countBits2(int num) {
        vector<int> result;
        for (auto i = 0; i <= num; i++) {
            result.push_back(count_one(i));
        }
        return result;
    }

    // 方法2: https://leetcode-cn.com/problems/counting-bits/solution/hen-qing-xi-de-si-lu-by-duadua/
    /*
    对于所有的数字，只有两类：
    奇数：二进制表示中，奇数一定比前面那个偶数多一个 1，因为多的就是最低位的 1。
          举例：
         0 = 0       1 = 1
         2 = 10      3 = 11
    偶数：二进制表示中，偶数中 1 的个数一定和除以 2 之后的那个数一样多。因为最低位是 0，除以 2
    就是右移一位，也就是把那个 0 抹掉而已，所以 1 的个数是不变的。 举例： 2 = 10       4 = 100       8 = 1000 3 = 11 6 =
    110       12 = 1100 另外，0 的 1 个数为 0，于是就可以根据奇偶性开始遍历计算了。

     */
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);
        if (num <= 0) {
            // result.push_back(0);
            return result;
        }

        for (int i = 1; i <= num; i++) {
            if (i % 2 == 1) {  //奇数
                result[i] = result[i - 1] + 1;
            } else {  //偶数
                result[i] = result[i / 2];
            }
        }

        return result;
    }
};
