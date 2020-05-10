package leetcode;

import java.lang.reflect.Array;
import java.util.Arrays;

/**
 * author：baixiaoling
 * date: 2017/12/18
 * <p>
 * description:
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * The replacement must be in-place, do not allocate extra memory.
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */
public class _31_NextPermutation {
    /*
    求排列组合的写一个组合
    解题思路：
    1 从数组是逆序的，则直接递增排列即可
    2 从后往前看， 找一个递增序列，将递增序列中前一个位置元素标记为index（下面例子中的2），将index和递增序列找那个刚好大于index的元素交换
    即交换 2 和3

    3 交换后，将index后面部分 7421 递增排列即可
    比如下面这个例子:从后往前，找到第一个大的元素， 3>2 ,交换3 和2，然后将3后面的元素递增排列即可
    1　　2　　7　　4　　3　　1
    1　　3　　7　　4　　2　　1
    1　　3　　1　　2　　4　　7
     */
    public void nextPermutation(int[] num) {
       if(num==null || num.length==0)  
            return;  
        int i = num.length-2;  
        while(i>=0 && num[i]>=num[i+1])  
            i--;
        
        if(i>=0){  
            int j=i+1;  
            while(j<num.length && num[j]>num[i])
                j++;
            j--;  
            swap(num,i,j);  
        }  
        reverse(num, i+1,num.length-1);  
    }    
    private void swap(int[] num, int i, int j){  
        int tmp = num[i];  
        num[i] = num[j];  
        num[j] = tmp;  
    }  
    private void reverse(int[] num, int i, int j){  
        while(i < j)  
            swap(num, i++, j--);  
    }

    public static void main(String[] args) {
        _31_NextPermutation object = new _31_NextPermutation();
        int[] nums = {4, 2, 0, 2, 3, 2, 0};
        object.nextPermutation(nums);
    }
}
