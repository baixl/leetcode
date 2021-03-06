/*
 * @lc app=leetcode.cn id=134 lang=cpp
 * [134] 加油站
 * https://leetcode-cn.com/problems/gas-station/description/
 * Medium (49.10%)
 * 在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
 * 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第
 * i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
 * 如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。
 * 说明: 
 * 如果题目有解，该答案即为唯一答案。
 * 输入数组均为非空数组，且长度相同。
 * 输入数组中的元素均为非负数。
 * 示例 1:
 * 输入:
 * gas  = [1,2,3,4,5]
 * cost = [3,4,5,1,2]
 * 输出: 3
 *
 * 解释:
 * 从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
 * 开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
 * 开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
 * 开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
 * 开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
 * 开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
 * 因此，3 可为起始索引。
 *
 * 示例 2:
 *
 * 输入:
 * gas  = [2,3,4]
 * cost = [3,4,3]
 *
 * 输出: -1
 *
 * 解释:
 * 你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
 * 我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
 * 开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
 * 开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
 * 你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
 * 因此，无论怎样，你都不可能绕环路行驶一周。
 *
 */

// @lc code=start
class Solution {
   public:
    /*
        解法：https://leetcode-cn.com/problems/gas-station/solution/jia-you-zhan-by-leetcode/

        1、若sum(gas) <sum(cost) 则一定到走一圈，因为总的油量不够一圈的花费
        2、记录两个临时变量:
            total_tank: 走一圈的剩余总油量，  最终如果 total_tank <0  则 return -1
            cur_tank: 到当前加油站，剩余的油量，
            如果 cur_tank < 0  则直接从下一个加油站开始，并且将cur_tank设置为0

            （从上一次重置的加油站到当前加油站的任意一个加油站出发，到达当前加油站之前， curr_tank 也一定会比 0 小:
            比如上一个位置是0：
            sum(gas[0:i-1] > sum(cost[0:i-1])
            sum(gas[0:i-1] + gas[i] < sum(cost[0:i-1])  + cost[i]
            比如从第1个加油站开始，gas[0] >= cost[0]
            sum(gas[1:i-1] + gas[i] < sum(cost[1:i-1])  + cost[i]

            ）
        3、如何保证，从下一个加油站开始，就一定能走一圈呢？
        比如当前起点为Ns，如何保证一圈后能回到Ns
        Ns->0 是可以到达， 如何保证 0->Ns 也是可以到达的呢？
        这里用反证法：
        假设 0->Ns之间有个节点k不可达，
        total_tank >=0 有
        sum [Ai] >=0  Ai= gas[i] -cost[i]
        Sum[Ai] = sum(A[0:k-1])  + sum(A[k:Ns-1]) +sum(A[Ns:N]) >=0
        由2 可知：sum(A[k:Ns-1]) <0
        => sum(A[0:k-1]) sum(A[Ns:N]) >=0

        但假设的从Ns出发，到不了k
        sum(A[0:k-1]) sum(A[Ns:N]) <= 0
        这就矛盾了，反正不存在这样的k
     */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() != cost.size()) return -1;
        int total_tank = 0, cur_tank = 0;
        int start = 0;
        for (auto i = 0; i < gas.size(); i++) {
            total_tank += gas[i] - cost[i];
            cur_tank += gas[i] - cost[i];
            if (cur_tank < 0) {
                start = i + 1;
                cur_tank = 0;
            }
        }
        return total_tank >= 0 ? start : -1;
    }
};
// @lc code=end
