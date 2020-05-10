/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */
class Solution {
   public:
    /*
    ：厄拉多塞筛法：
    申请一个辅助的判别数组， 若一个数是质素，则其*2 *3 *4 ... 都不是质素
    */
    int countPrimes(int n) {
        if (n <= 1) return 0;
        vector<int> temp(n+1, 1);
        int count = 0;
        for (auto i = 2; i < n; i++) {
            if (temp[i] == 1) {
                count ++;
                for (auto j = i + i; j < n; j += i) {
                    temp[j] = 0;
                }
            }
        }
        return count;
    }
};
