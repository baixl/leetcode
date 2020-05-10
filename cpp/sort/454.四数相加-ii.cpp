/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 *
 * https://leetcode-cn.com/problems/4sum-ii/description/
 *
 * Medium (53.80%)
 * 给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] +
 * D[l] = 0。
 * 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2^28 到 2^28 - 1
 * 之间，最终结果不会超过 2^31 - 1 。
 * 例如:
 * 输入:
 * A = [ 1, 2]
 * B = [-2,-1]
 * C = [-1, 2]
 * D = [ 0, 2]
 *
 * 输出:
 * 2
 *
 * 解释:
 * 两个元组如下:
 * 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> map;  // 遍历A B构建查找表，<和， 次数>

        for (auto i = 0; i < A.size(); i++) {
            for (auto j = 0; j < B.size(); j++) {
                int sum = A[i] + B[j];
                if (map.find(sum) != map.end())
                    map[sum]++;
                else
                    map[sum] = 1;
            }
        }
        int res = 0;
        for (auto k = 0; k < C.size(); k++) {
            for (auto l = 0; l < D.size(); l++) {
                int sum = C[k] + D[l];
                sum *= -1;
                if (map.find(sum) != map.end()) res += map[sum];
            }
        }
        return res;
    }
};
// @lc code=end
