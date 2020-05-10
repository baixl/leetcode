/*
 * @lc app=leetcode.cn id=276 lang=cpp
 *
有 k 种颜色的涂料和一个包含 n 个栅栏柱的栅栏，每个栅栏柱可以用其中一种颜色进行上色。
你需要给所有栅栏柱上色，并且保证其中相邻的栅栏柱 最多连续两个 颜色相同。然后，返回所有有效涂色的方案数。
注意:
n 和 k 均为非负的整数。

示例:

输入: n = 3，k = 2
输出: 6
解析: 用 c1 表示颜色 1，c2 表示颜色 2，所有可能的涂色方案有:

            柱 1    柱 2   柱 3     
 -----      -----  -----  -----       
   1         c1     c1     c2 
   2         c1     c2     c1 
   3         c1     c2     c2 
   4         c2     c1     c1  
   5         c2     c1     c2
   6         c2     c2     c1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/paint-fence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class Solution {
public:
    /*
     动态规划，在涂第n个柱子时，有两种情况
    dp[n]： 若n与n-1颜色相同，则一定与n-2不同， 则 dp[n] = dp[n-2] *(k-1)
    dp[n]： 若n与n-1颜色不同， 则dp[n] = dp[n-1] * (k-1)
    */
    int numWays(int n, int k) {
        if (n==0) return 0;
        if (n==1) return k;
        if (n==2) return k*k;
        vector<int>dp(n, 0);
        dp[0] = k;
        dp[1] = k*k;
        for (auto i=2; i<n; i++) {
            dp[i] = dp[i-2] *(k-1) + dp[i-1]*(k-1);
        } 
        return dp[n-1];
    }
};