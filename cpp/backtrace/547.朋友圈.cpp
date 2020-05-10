/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 *
 * https://leetcode-cn.com/problems/friend-circles/description/
 * 班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是
 * C 的朋友，那么我们可以认为 A 也是 C 的朋友。所谓的朋友圈，是指所有朋友的集合。
 
 * 给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j
 * 个学生互为朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。
 *
 * 示例 1:
 * 输入:
 * [[1,1,0],
 * ⁠[1,1,0],
 * ⁠[0,0,1]]
 * 输出: 2
 * 说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
 * 第2个学生自己在一个朋友圈。所以返回2。
 *
 * 示例 2:
 *
 * 输入:
 * [[1,1,0],
 * ⁠[1,1,1],
 * ⁠[0,1,1]]
 * 输出: 1
 * 说明：已知学生0和学生1互为朋友，学生1和学生2互为朋友，所以学生0和学生2也是朋友，所以他们三个在一个朋友圈，返回1。
 *
 * 注意：
 *
 * N 在[1,200]的范围内。
 * 对于所有学生，有M[i][i] = 1。
 * 如果有M[i][j] = 1，则有M[j][i] = 1。
 */
class Solution {
   public:
    // 方法1：并查集：https://leetcode-cn.com/problems/friend-circles/solution/c-bing-cha-ji-shi-xian-by-zhang-zhe/
    //并查集没看太懂 TODO：

    // 方法2：DFS
    /*
    朋友圈最多数量为M.size() : 每个人自成一个圈子
    使用visited数组，标记每个人是否在DFS中被访问过
    */
    void dfs(vector<vector<int>>& M, vector<int>& visited, int i) {
        visited[i] = 1;
        for (auto j = 0; j < M.size(); j++) {
            if (visited[j] == 0 && M[i][j] == 1) {
                dfs(M, visited, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& M) {
        if (M.size() <= 0 || M[0].size() <= 0) {
            return 0;
        }
        vector<int> visited(M.size(), 0);
        int result = 0;
        for (auto i = 0; i < M.size(); i++) {  //遍历每个人
            if (visited[i] == 0) {
                result++;
                dfs(M, visited, i);
            }
        }
        return result;
    }
};
