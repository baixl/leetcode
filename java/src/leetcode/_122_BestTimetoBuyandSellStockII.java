package leetcode;

import java.util.Arrays;

/**
 * author：baixiaoling
 * date: 2018/1/9
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * <p>
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like
 * (ie, buy one and sell one share of the stock multiple times). However,
 * you may not engage in multiple transactions at the same time
 * (ie, you must sell the stock before you buy again).
 * 解题思路：
 * 动态规划
 * 因为可以随时买卖，则使用dp数组记录当前位置所能获得的最大收益
 * 估计上涨：prices[i] > prices[i - 1]  ，dp[i] =  dp[i-1] + prices[i] - prices[i-1];
 * 估计下跌或不变，dp[i]维持不变
 */
public class _122_BestTimetoBuyandSellStockII {

    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) return 0;
        int[] dp = new int[prices.length];
        dp[0] = 0;
        int max = Integer.MIN_VALUE;
        int min = prices[0];
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > prices[i - 1]) {
                dp[i] = dp[i - 1] + prices[i] - prices[i - 1];
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[prices.length - 1];
    }


    public static void main(String[] args) {
        _122_BestTimetoBuyandSellStockII object = new _122_BestTimetoBuyandSellStockII();
        int[] prices = {2, 3, 5, 0, 1};
        System.out.println(object.maxProfit(prices));
    }
}
