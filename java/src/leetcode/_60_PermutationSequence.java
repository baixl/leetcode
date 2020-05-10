package leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * author：baixiaoling
 * date: 2017/12/24
 * <p>
 * description:
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 * Note: Given n will be between 1 and 9 inclusive.
 */
public class _60_PermutationSequence {

    // todo   未解决，待定
    /*
    http://www.cnblogs.com/TenosDoIt/p/3721918.html
    我们以n = 4，k = 17为例，数组src = [1,2,3,...,n]。

第17个排列的第一个数是什么呢：我们知道以某个数固定开头的排列个数 = (n-1)! = 3! = 6, 即以1和2开头的排列总共6*2 = 12个，12 < 17, 因此第17个排列的第一个数不可能是1或者2，6*3 > 17, 因此第17个排列的第一个数是3。即第17个排列的第一个数是原数组（原数组递增有序）的第m = upper(17/6) = 3（upper表示向上取整）个数。                                           本文地址

第一个数固定后，我们从src数组中删除该数，那么就相当于在当前src的基础上求第k - (m-1)*(n-1)! = 17 - 2*6 = 5个排列，因此可以递归的求解该问题。


     */
    public String getPermutation(int n, int k) {
        if (k <= 0) return "";

        List<Integer> nums = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            nums.add(i + 1);
        }
//        k--;
        ArrayList<Integer> list = new ArrayList<>();

        list.add(1);
        for (int i = 1; i < n; i++) {
            list.add(list.get(i - 1) * (i + 1));
        }


        String s = "";

        for (int i = n - 1; i >= 1; i--) {
            int j = k / list.get(i - 1);
            k %= list.get(i - 1);
            s += nums.get(j);
//            nums.remove(j);

        }

        return s;
//
//        ArrayList<Integer> nums = new ArrayList<>();
//        for (int i = 1; i <= n; i++) {
//            nums.add(i);
//        }
//
//        int round = n - 1;
//        StringBuilder result = new StringBuilder();
//        while (round >= 0) {
//            int index = k / factorial;
//            k %= factorial;
//            result.append(nums.get(k));
//            nums.remove(index);
//            if (round > 0) {
//                factorial /= round;
//            }
//            round--;
//        }
//        return result.toString();
    }

    public static void main(String[] args) {
        _60_PermutationSequence object = new _60_PermutationSequence();
        System.out.println(object.getPermutation(3, 3));
    }
}
