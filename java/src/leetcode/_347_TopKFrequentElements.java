package leetcode;

import java.util.*;

/**
 * author：baixiaoling
 * date: 2018/1/11
 * <p>
 * description:
 * Given a non-empty array of integers, return the k most frequent elements.
 * <p>
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 * <p>
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 * 解题思路：
 * 和215题 第k大元素有些类似
 */
public class _347_TopKFrequentElements {
    /*
    解法1： 使用优先级队列
    1 计算频率：使用hashmap
    2 使用优先级队列存放topk个，由于要求频率最多的k个，这里使用小顶堆（priorityQueue默认是升序的小顶堆）
    注意：priorityQueue存放的map的entry，最终需要对queue中的元素逆序
     */
    public List<Integer> topKFrequent(int[] nums, int k) {
        List<Integer> list = new ArrayList<>();
        if (nums == null || nums.length == 0 || k <= 0) return list;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                map.put(nums[i], map.get(nums[i]) + 1);
            } else {
                map.put(nums[i], 1);
            }
        }

        Queue<Map.Entry<Integer, Integer>> queue = new PriorityQueue<>(new Comparator<Map.Entry<Integer, Integer>>() {
            @Override
            public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
                return o1.getValue() - o2.getValue();
            }
        });

        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (queue.isEmpty() || queue.size() < k) {
                queue.offer(entry);
            } else {
                queue.offer(entry);
                queue.poll();
            }
        }

        for (Map.Entry<Integer, Integer> entry : queue) {
            list.add(entry.getKey());
        }
        Collections.reverse(list);
        return list;
    }

    /*
    方法2： 使用桶排序
     */
    public List<Integer> topKFrequent2(int[] nums, int k) {
        List<Integer> list = new ArrayList<>();
        if (nums == null || nums.length == 0 || k <= 0) return list;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                map.put(nums[i], map.get(nums[i]) + 1);
            } else {
                map.put(nums[i], 1);
            }
        }

        // 使用桶排序，相同词频的元素放到同一个桶下面
        List<Integer>[] bucket = new List[nums.length + 1];
        for (Integer key : map.keySet()) {
            int times = map.get(key);
            if (bucket[times] == null) {
                bucket[times] = new ArrayList<>();
            }
            bucket[times].add(key);
        }

        for (int i = bucket.length - 1; i >= 0; i--) {
            if (bucket[i] != null) {
                for (int j = 0; j < bucket[i].size(); j++) {
                    list.add(bucket[i].get(j));
                }
                if (list.size() >= k) {
                    return list;
                }
            }
        }
        return list;
    }

    public static void main(String[] args) {
        _347_TopKFrequentElements object = new _347_TopKFrequentElements();
        int[] nums = {1, 1, 1, 2, 2, 3};
        System.out.println(object.topKFrequent2(nums, 2));
    }
}
