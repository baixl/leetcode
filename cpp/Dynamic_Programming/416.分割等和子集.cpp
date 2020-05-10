/*
 * @lc app=leetcode.cn id=416 lang=cpp
 * [416] 分割等和子集
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/description/
 * algorithms
 * Medium (44.66%)
 * 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 注意:
 * 每个数组中的元素不会超过 100
 * 数组的大小不会超过 200
 * 
 * 示例 1:
 * 
 * 输入: [1, 5, 11, 5]
 * 输出: true
 * 解释: 数组可以分割成 [1, 5, 5] 和 [11].
 * 
 * 示例 2:
 * 输入: [1, 2, 3, 5]
 * 输出: false
 * 解释: 数组不能分割成两个元素和相等的子集.
 * 
 */
/*
动态规划： 原型 01背包问题，相似题目，零钱兑换、零钱兑换2：

1、等价转换：做这个题需要先做一个等价转换： 是否可以从这个数组中挑选出一些正整数，使得这些正整数之和刚好是所有元素和的一半
2、01 背包问题的特点，每个数字只出现一次。具体做法：
化一个 len行，target+1 列的表格，len是物品数，target是背包容量。len 行表示一个一个物品考虑，target + 1多出来的那 1 列，表示背包容量从 0 开始，很多时候，我们需要考虑这个容量为 0 的数值。
3、状态定义：dp[i][j]表示从数组的[0, i]这个子区间内挑选一些正整数，每个数只能用一次，使得这些数的和恰好等于 j。
状态转移方程：很多时候，状态转移方程思考的角度是“分类讨论”，对于“0-1 背包问题”而言就是“当前考虑到的数字选与不选”。
    1、不选择 nums[i]，如果在 [0, i - 1] 这个子区间内已经有一部分元素，使得它们的和为 j ，那么 dp[i][j] = true；
    2、选择 nums[i]，如果在 [0, i - 1] 这个子区间内就得找到一部分元素，使得它们的和为 j - nums[i]。

状态转移方程是：
    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - nums[i]]

4、边界条件：
一般写出状态转移方程以后，就需要考虑边界条件（一般而言也是初始化条件）。
1、j - nums[i] 作为数组的下标，一定得保证大于等于 0 ，因此 nums[i] <= j；
2、注意到一种非常特殊的情况：j 恰好等于 nums[i]，即单独 nums[j] 这个数恰好等于此时“背包的容积” j，这也是符合题意的。

*/
class Solution {
public:
    // 01 背包，优化到1维数组，
    /*
    在“填表格”的时候，当前行只参考了上一行的值，因此状态数组可以只设置 2 行，使用“滚动数组”的技巧“填表格”即可；
    */
    bool canPartition(vector<int>& nums) {
        if (nums.empty()) return false;
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }
        if (sum % 2 == 1)  return false; // 和为奇数
        int target = sum / 2;
        // dp[i][j]表示从数组的[0, i]这个子区间内挑选一些正整数，每个数只能用一次，使得这些数的和恰好等于 j。
        
        int len = nums.size();
        vector<bool> dp(target+1, false);
        // 初始化第1行
        if (nums[0] <= target) {
            dp[nums[0]] = true;
        }
        
        if (nums[0] <= target) {
            dp[nums[0]] = true;
        }

        for (int i = 1; i < len; i++) {
            for (int j = target; j >= nums[i]; j--) { //  这里逆序的考虑， 如果是正序，则前面的dp 可能被多次更新，
            // 比如 [1,2,5] dp[1] =true, dp[2]= true, dp[3] = dp[3] || dp[3-1] = true , dp[4] = d[4] || dp[4-1] = dp[4] || d[[3] = true, 这是错的。
            // dp[3]是前面计算的结果. 使用逆序遍历，则可以避免这种错误
                if (dp[target]) {
                    return true;
                }
                dp[j] = dp[j] || dp[j - nums[i]];
            }
            cout << i <<" --  ";
            for(auto i : dp) {
                cout << i <<" > ";
            }
            cout << "\n";
        }
        return dp[target];
    }
    // 01 背包，使用二维数组
    bool canPartition2(vector<int>& nums) {
        if (nums.empty()) return false;
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }
        if (sum % 2 == 1)  return false; // 和为奇数
        int target = sum / 2;

        int len = nums.size(); // 物品的数量，
        vector<vector<bool>> dp(len, vector<bool>(target +1, false)); // dp[len][target+1] : 行：物品索引，列：容量 包括0.  
        // dp[i][j]表示从数组的[0, i]这个子区间内挑选一些正整数，每个数只能用一次，使得这些数的和恰好等于 j。

        // 初始化第1行
        if (nums[0] <= target) {
            dp[0][nums[0]] = true;
        }
        for(auto i =1; i < len; i++) {
            for (auto j = 0; j <= target; j++) {
                if (nums[i] == j) {
                    dp[i][j] = true;
                    continue;
                }
                if (nums[i] < j) {
                    dp[i][j] =  dp[i-1][j] || dp[i-1][j-nums[i]];
                }
            }
            // 剪枝 优化点
            if (dp[i][target] == true) return true;
        }
        return dp[len -1][target];
    }
};// @lc code=end

