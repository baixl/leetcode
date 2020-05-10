/*
 * @lc app=leetcode.cn id=207 lang=cpp
 * [207] 课程表
 * https://leetcode-cn.com/problems/course-schedule/description/
 * Medium (48.69%)
 * 现在你总共有 n 门课需要选，记为 0 到 n-1。
 * 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
 * 给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？
 * 示例 1:
 * 输入: 2, [[1,0]]
 * 输出: true
 * 解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
 * 示例 2:
 * 输入: 2, [[1,0],[0,1]]
 * 输出: false
 * 解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0
 * 之前，你还应先完成课程 1。这是不可能的。 说明:
 * 输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。 你可以假定输入的先决条件中没有重复的边。
 * 提示:
 * 这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能选取所有课程进行学习。
 * 通过 DFS 进行拓扑排序 - 一个关于Coursera的精彩视频教程（21分钟），介绍拓扑排序的基本概念。
 * 拓扑排序也可以通过 BFS 完成。
 */

// @lc code=start
class Solution {
   public:
    /*
    https://leetcode-cn.com/problems/course-schedule/solution/course-schedule-tuo-bu-pai-xu-bfsdfsliang-chong-fa/
    方法1：BFS，借助Queue
    拓扑排序：依次删除所有入度为0的节点， 如果图构成拖不排序(节点是有向无环图)，则所有节点都将依次删除
    具体做法：
    1、先统计所有节点的入度
    2、将所有入度为0的节点入队列
    3、遍历队列，将所有入度为0的节点删除(出队列），并将指向的节点的入度-1
    4、若所有指向(邻接)节点入度为0，则再次入队列
    5、判断所有阶段是否都依次删除
    */
    bool canFinish1(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegress(numCourses, 0);  // 入度表，记录所有节点的入度
        for (auto i = 0; i < prerequisites.size(); i++) {
            vector<int> cur_vec = prerequisites[i];
            indegress[cur_vec[0]]++;  // 入度加+1
        }

        std::queue<int> q;  // BFS 辅助队列, 保留所有入度为0的节点
        for (auto i = 0; i < numCourses; i++) {
            if (indegress[i] == 0) {  // 入度为0的点
                q.push(i);
            }
        }

        while (!q.empty()) {
            int pre = q.front();
            q.pop();
            numCourses--;

            for (auto i = 0; i < prerequisites.size(); i++) {
                vector<int> cur_vec = prerequisites[i];
                if (cur_vec[1] != pre) continue;
                if (--indegress[cur_vec[0]] == 0) q.push(cur_vec[0]);  // 当入度为0时， 也加入到队列中
            }
        }
        return numCourses == 0;  // 当所有节点都遍历了一遍时， numCourses == 0
    }
    /*
    方法2： DFS
    1、先构建邻接矩阵
    2、新建辅助数组vector<int> vistied(numCourses, 0);
    未被 DFS 访问：vi's'tie'd[i] == 0；
    已被其他节点启动的DFS访问：vistied[i] == -1；
    已被当前节点启动的DFS访问：vistied[i] == 1。
    3、将当前访问节点 i 对应 flag[i] 置 1，即标记其被本轮 DFS 访问过；
    4、递归访问当前节点 i 的所有邻接节点 j，当发现环直接返回 False；
    5、当前节点所有邻接节点已被遍历，并没有发现环，则将当前节点 flag 置为 −1 并返回 True
    */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacency(numCourses, vector<int>(numCourses, 0));  // 邻接矩阵
        for (auto i = 0; i < prerequisites.size(); i++) {
            vector<int> cur_vec = prerequisites[i];
            adjacency[cur_vec[1]][cur_vec[0]] = 1;
        }
        vector<int> vistied(numCourses, 0);
        for (auto i = 0; i < numCourses; i++) {
            if (!dfs(adjacency, vistied, i)) return false;
        }

        return true;
    }
    bool dfs(vector<vector<int>>& adjacency, vector<int>& vistied, int i) {
        if (vistied[i] == 1) return false;  // 被当前节点启动的DFS访问，存在环
        if (vistied[i] == -1) return true;  // 当前节点已其他节点启动的DFS访问，无需再重复进行
        vistied[i] = 1;
        for (auto j = 0; j < adjacency.size(); j++) {
            if (adjacency[i][j] == 1 && !dfs(adjacency, vistied, j)) return false;
        }
        vistied[i] = -1;
        return true;
    }
};
// @lc code=end
