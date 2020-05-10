package leetcode;

import leetcode.domain.TreeNode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * author：baixiaoling
 * date: 2018/1/7
 * <p>
 * description:
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 * <p>
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 * <p>
 * 1         3     3      2      1
 * \       /     /      / \      \
 * 3     2     1      1   3      2
 * /     /       \                 \
 * 2     1         2                 3
 * Seen this question in a real interview before?  YesNo
 * <p>
 * <p>
 * 解题思路：动态规划：
 * 考虑二叉搜索树的性质，对任意的i为根节点，则左子树一定是[0, i-1],右子树一定是[i+1, n]
 * 假设左子树有m中组合，右子树有n种组合，则总共的组合方式是mxn,
 * 可以使用动态规划的方式，使用一个dp数组表示i个节点下面的排列个数，则有
 * dp[i] = sum(dp[k] * dp[i - k -1]) 0 <= k < i
 * <p>
 * http://blog.csdn.net/linhuanmars/article/details/24761459
 * https://siddontang.gitbooks.io/leetcode-solution/content/dynamic_programming/unique_binary_search_trees.html
 * <p>
 * 卡特兰数？
 */
public class _96_UniqueBinarySearchTrees {
    public int numTrees(int n) {
        if (n < 0) return 0;
        int[] dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // 以j作为根节点，左边树节点个数j,右边树节点个数i-1-j,
                // dp[i]表示i个节点下面排列的组合数
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }


    public static void main(String[] args) {
        _96_UniqueBinarySearchTrees objecct = new _96_UniqueBinarySearchTrees();

        System.out.println(objecct.numTrees(3));

    }
}
