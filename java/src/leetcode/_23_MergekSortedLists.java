package leetcode;

import leetcode.domain.ListNode;

import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * author：baixiaoling
 * date: 2017/12/16
 * <p>
 * description:
 */
public class _23_MergekSortedLists {
    /*
    排序k个有序链表
    方法1： 归并排序的思路，分治的思想，讲k个链表一分为2（直到只有两个链表为止，复用21题的合并有个有序链表的问题）
    http://blog.csdn.net/linhuanmars/article/details/19899259
    方法2：使用一个大小为k的堆，一次读取k个链表的头通过堆进行排序

     */
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0)
            return null;
        return helper(lists, 0, lists.length - 1);
    }

    private ListNode helper(ListNode[] lists, int left, int right) {
        if (left < right) {
            int m = (left + right) / 2;
            return mergeTwoLists(helper(lists, left, m), helper(lists, m + 1, right));
        }
        return lists[left];
    }

    private ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        ListNode index1 = l1, index2 = l2;
        ListNode pre = new ListNode(0);
        ListNode dummy = pre;
        while (index1 != null && index2 != null) {
            if (index1.val < index2.val) {
                pre.next = new ListNode(index1.val);
                index1 = index1.next;
                pre = pre.next;
            } else {
                pre.next = new ListNode(index2.val);
                index2 = index2.next;
                pre = pre.next;
            }
        }

        if (index1 != null) {
            pre.next = index1;
        }
        if (index2 != null) {
            pre.next = index2;
        }
        return dummy.next;
    }

    /*
    方法2： 使用一个大小为k的堆进行排序
    每次都取堆顶b元素（最小），然后将该元素的下一个元素入堆（若为空则跳过）
    PriorityQueue 默认是最大元素在堆顶
     */
    public ListNode mergeKLists2(ListNode[] lists) {
        if (lists == null || lists.length == 0)
            return null;
        PriorityQueue<ListNode> heap = new PriorityQueue<>(new Comparator<ListNode>() {
            @Override
            public int compare(ListNode o1, ListNode o2) {
                return o1.val - o2.val;
            }
        });
        for (int i = 0; i < lists.length; i++) {
            ListNode node = lists[i];
            if (node != null) {
                heap.offer(node);
            }
        }
        ListNode head = null;
        ListNode pre = head;
        while (heap.size() > 0) {
            ListNode current = heap.poll();
            if (head == null) {
                head = current;
                pre = head;
            } else {
                pre.next = current;
                pre = current;
            }

            if (current.next != null) {
                heap.offer(current.next);
            }
        }
        return head;
    }

}
