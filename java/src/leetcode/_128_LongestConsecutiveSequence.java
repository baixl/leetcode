package leetcode;

import java.util.HashMap;
import java.util.Map;

/**
 * author：baixiaoling
 * date: 2017/12/23
 * <p>
 * description:
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 * <p>
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 * <p>
 * Your algorithm should run in O(n) complexity.
 */
public class _128_LongestConsecutiveSequence {
    /*
    使用hash表存储每个元素的连续序列的长度
    遍历数据，对每一个元素，考察其+1 和-1是否在hash表中
     */
    public int longestConsecutive(int[] nums) {

        if (nums == null) return 0;
        if (nums.length <= 1) return nums.length;
        Map<Integer, Integer> map = new HashMap<>();
        int result = 0;
        for (Integer integer : nums) {
            if (map.containsKey(integer)) {
                continue; // 无序数组，有可能有重复值
            }
            int left = map.containsKey(integer - 1) ? map.get(integer - 1) : 0;
            int right = map.containsKey(integer + 1) ? map.get(integer + 1) : 0;
            int sum = left + right + 1; // 加上左右连续序列 长度
            map.put(integer, sum);
            result = Math.max(result, sum);

            map.put(integer - left, sum); //更新最左最右边界的值
            map.put(integer + right, sum);

        }
        return result;
    }

    public static void main(String[] args) {
        _128_LongestConsecutiveSequence object = new _128_LongestConsecutiveSequence();
        int[] nums = {100, 4, 200, 1, 3, 2};
        System.out.println(object.longestConsecutive(nums));
    }
}
