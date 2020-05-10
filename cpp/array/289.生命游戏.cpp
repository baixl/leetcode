/*
https://leetcode-cn.com/problems/game-of-life/
 * [289] 生命游戏
 给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。
 每个细胞具有一个初始状态 live（1）即为活细胞， 或 dead（0）即为死细胞。
 每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：

如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
根据当前状态，写一个函数来计算面板上细胞的下一个（一次更新后的）状态。
下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。
输入:
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
输出:
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
 */
#include <vector>
class Solution {
   public:
    // 暴力解决， 直接copy一个新数组， 但做不到原地
    /* 数组中原来有两个值： 更新过程有4个状态：

    1、活到死 活细胞周围8个位置活细胞数 <2
    2、活到活 周围8个位置有2或者3个活
    3、活到死 周围8个有超过3个活
    4、死到活 死细胞周围有超过3个活
    5、死到死

    这里要求数组同时更新 和原地算法，不能使用额外的空间，
    原来数组有两个值：0、1， 需要新增两个值表示：活到死 -1，和死到活 2
    */
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) {
            return;
        }
        int row = board.size();
        int column = board[0].size();
        for (auto i = 0; i < row; i++) {
            for (auto j = 0; j < column; j++) {
                check(board, i, j);
            }
        }
        for (auto i = 0; i < row; i++) {
            for (auto j = 0; j < column; j++) {
                if (board[i][j] == -1) {
                    board[i][j] = 0;
                } else if (board[i][j] == 2) {
                    board[i][j] = 1;
                }
            }
        }
    }

    void check(vector<vector<int>>& board, int i, int j) {
        // 1、计算当前节点周围活细胞的数量
        int count = 0;

        int left = max(j - 1, 0);
        int row = board.size();
        int column = board[i].size();
        int right = min(j + 1, column - 1);
        int top = max(i - 1, 0);
        int bottom = min(i + 1, row - 1);

        for (auto x = top; x <= bottom; x++) {
            for (auto y = left; y <= right; y++) {
                if (board[x][y] == 1 || board[x][y] == -1) {
                    count++;  // 这儿把自己也算进去了
                }
            }
        }

        if (board[i][j] == 1) {
            count--;  // 减去自己
            if (count < 2 || count > 3) {
                board[i][j] = -1;
            }
        } else if (board[i][j] == 0) {
            if (count == 3) {
                board[i][j] = 2;
            }
        }
    }
};
