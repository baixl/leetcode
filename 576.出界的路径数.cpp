/*
 * @lc app=leetcode.cn id=576 lang=cpp
 *
 * [576] 出界的路径数
 *
 * https://leetcode-cn.com/problems/out-of-boundary-paths/description/
 *
 * Medium (36.04%)
 * 给定一个 m × n 的网格和一个球。球的起始坐标为 (i,j)
 * ，你可以将球移到相邻的单元格内，或者往上、下、左、右四个方向上移动使球穿过网格边界。但是，你最多可以移动 N
 * 次。找出可以将球移出边界的路径数量。答案可能非常大，返回 结果 mod 10^9 + 7 的值。
 *
 * 示例 1：
 * 输入: m = 2, n = 2, N = 2, i = 0, j = 0
 * 输出: 6
 * 解释:
 *
 * 示例 2：
 * 输入: m = 1, n = 3, N = 3, i = 0, j = 1
 * 输出: 12
 * 解释:
 *
 * 说明:
 * 球一旦出界，就不能再被移动回网格内。
 * 网格的长度和高度在 [1,50] 的范围内。
 * N 在 [0,50] 的范围内。
 *
 */

// @lc code=start
class Solution {
   public:
    // DFS+记忆化搜索
    int result = 0;
    unordered_map<string, long> map;
    int findPaths(int m, int n, int N, int i, int j) {
        if (m <= 0 || n <= 0 || i < 0 || i >= m || j < 0 || j >= n) return 0;
        return dfs(m, n, N, i, j, 0);
    }

    int dfs(int m, int n, int N, int i, int j, int cur_step) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            if (cur_step <= N) {
                return 1;
            }
            return 0;
        }
        string key = to_string(i) + "-" + to_string(j) +"-"+to_string(cur_step);
        if (map.find(key) != map.end()) {
            return map[key];
        }
        long count = 0;
        if (cur_step <= N) {
            count += dfs(m, n, N, i + 1, j, cur_step + 1);
            count += dfs(m, n, N, i - 1, j, cur_step + 1);
            count += dfs(m, n, N, i, j + 1, cur_step + 1);
            count += dfs(m, n, N, i, j - 1, cur_step + 1);
        }
        map[key] = count%1000000007;
        return count%1000000007;
    }
};
// @lc code=end
