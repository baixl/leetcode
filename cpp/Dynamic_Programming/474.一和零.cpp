/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 *
 * https://leetcode-cn.com/problems/ones-and-zeroes/description/
 * Medium (49.87%)
 * 在计算机界中，我们总是追求用有限的资源获取最大的收益。
 * 现在，假设你分别支配着 m 个 0 和 n 个 1。另外，还有一个仅包含 0 和 1 字符串的数组。
 * 你的任务是使用给定的 m 个 0 和 n 个 1 ，找到能拼出存在于数组中的字符串的最大数量。每个 0 和 1 至多被使用一次。
 * 
 * 注意:
 * 给定 0 和 1 的数量都不会超过 100。
 * 给定字符串数组的长度不会超过 600。
 * 示例 1:
 * 输入: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
 * 输出: 4
 * 
 * 解释: 总共 4 个字符串可以通过 5 个 0 和 3 个 1 拼出，即 "10","0001","1","0" 。
 * 示例 2:
 * 输入: Array = {"10", "0", "1"}, m = 1, n = 1
 * 输出: 2
 * 
 * 解释: 你可以拼出 "10"，但之后就没有剩余数字了。更好的选择是拼出 "0" 和 "1" 。
 */

// @lc code=start
class Solution {
public:
    /*
    这道题和经典的背包问题很类似，不同的是在背包问题中，我们只有一种容量，而在这道题中，我们有 0 和 1 两种容量。每个物品（字符串）需要分别占用 0 和 1 的若干容量，并且所有物品的价值均为 1。因此我们可以使用二维的动态规划。

我们用 dp(i, j) 表示使用 i 个 0 和 j 个 1，最多能拼出的字符串数目，那么状态转移方程为：

dp(i, j) = max(1 + dp(i - cost_zero[k], j - cost_one[k]))
    if i >= cost_zero[k] and j >= cost_one[k]
其中 k 表示第 k 个字符串，cost_zero[k] 和 cost_one[k] 表示该字符串中 0 和 1 的个数。我们依次枚举这些字符串，并根据状态转移方程更新所有的 dp(i, j)。注意由于每个字符串只能使用一次（即有限背包），因此在更新 dp(i, j) 时，i 和 j 都需要从大到小进行枚举。
最终的答案即为所有 dp(i, j) 中的最大值。

作者：LeetCode
链接：https://leetcode-cn.com/problems/ones-and-zeroes/solution/yi-he-ling-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(string& s: strs) {
            vector<int> count = count_one_zero(s);
            for(auto zero = m; zero >= count[0]; zero--) {
                for(auto one = n; one >= count[1]; one--) {
                    dp[zero][one] = max(1+dp[zero-count[0]][one-count[1]], dp[zero][one]);
                }
            }
        }
        return dp[m][n];
    }
    vector<int> count_one_zero(string& s) {
        vector<int> res(2, 0);
        for(auto c: s) {
            if (c=='0') res[0]++;
            if (c=='1') res[1] ++;
        }
        return res;
    }
};

// @lc code=end

