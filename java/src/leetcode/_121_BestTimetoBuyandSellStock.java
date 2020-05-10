package leetcode;

/**
 * author：baixiaoling
 * date: 2018/1/5
 * <p>
 * description:
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction
 * (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 * <p>
 * Example 1:
 * Input: [7, 1, 5, 3, 6, 4]
 * Output: 5
 * <p>
 * max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
 * Example 2:
 * Input: [7, 6, 4, 3, 1]
 * Output: 0
 * <p>
 * In this case, no transaction is done, i.e. max profit = 0.
 */
public class _121_BestTimetoBuyandSellStock {

    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) return 0;
        int max = 0;
        int currentMin = prices[0];
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > currentMin) {
                max = Math.max(prices[i] - currentMin, max);
            } else {
                currentMin = prices[i];
            }
        }
        return max;
    }

    public static void main(String[] args) {
        _121_BestTimetoBuyandSellStock object = new _121_BestTimetoBuyandSellStock();
        int[] prices = {7, 1, 5, 3, 6, 4};
        System.out.println(object.maxProfit(prices));
    }
}
