package leetcode;

/**
 * author：baixiaoling
 * date: 2018/1/11
 * <p>
 * description:
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 * <p>
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel
 * from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 * <p>
 * Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 * <p>
 * Note:
 * The solution is guaranteed to be unique.
 * 有唯一结果
 * 解题思路:
 * 这道题目的意思是，可以从每个gas station开始，能到达下一个gas station的条件是 left+ gas[i]-cost[i] >=0
 * 如果一个一个节点遍历，则处理起来很麻烦。
 * 这道题的思路是： 若所有的gas加起来的和都比所有cost加起来的和更小，则肯定到不了终点。
 * 这道题有个提示结果是唯一的，则假设某个gas station开始时，sum + gas[i] -cost[i] <0,则开始节点肯定是在该气站的下一个气站，结果应该是i+1
 */
public class _134_GasStation {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        if (gas == null || gas.length == 0 || cost == null || cost.length == 0) return -1;
        int sum = 0;
        int totalRest = 0;
        int index = 0;
        for (int i = 0; i < gas.length; i++) {
            sum += gas[i] - cost[i];
            totalRest += gas[i] - cost[i];
            if (sum < 0) {
                index = i + 1;
                sum = 0;
            }

        }
        if (totalRest < 0) {
            return -1;
        } else {
            return index;
        }
    }

    public static void main(String[] args) {
        _134_GasStation object = new _134_GasStation();
        int[] gas = {2, 4};
        int[] cost = {3, 4};
        System.out.println(object.canCompleteCircuit(gas, cost));
    }
}
