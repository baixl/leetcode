package leetcode;

import leetcode.domain.ListNode;

import java.util.List;

/**
 * author：baixiaoling
 * date: 2017/12/25
 * <p>
 * description:
 * Sort a linked list in O(n log n) time using constant space complexity.
 */
public class _148_SortList {
    /*
    常数空间且 O(nlogn)，单链表适合用归并排序，双向链表适合用快速排序。本题可以复 用”Merge Two Sorted Lists” 的代码。

   一直折半操作，直到只有两个节点，使用归并操作进行排序

     */
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode fast = head, slow = head;

        //快慢指针，找到中间位置
        while (fast.next != null && fast.next.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        // 从中间断开
        fast = slow;
        slow = slow.next;
        fast.next = null;
        ListNode h1 = sortList(head);
        ListNode h2 = sortList(slow);
        return merge(h1, h2);

    }

    private ListNode merge(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(-1);
        ListNode p = dummy;
        while (l1 != null && l2 != null) {
            int val1 = l1.val;
            int val2 = l2.val;
            if (val1 < val2) {
                p.next = new ListNode(val1);
                l1 = l1.next;
                p = p.next;
            } else {
                p.next = new ListNode(val2);
                l2 = l2.next;
                p = p.next;
            }
        }
        if (l1 != null) p.next = l1;
        if (l2 != null) p.next = l2;
        return dummy.next;
    }

    public static void main(String[] args) {
        _148_SortList object = new _148_SortList();
        ListNode node1 = new ListNode(5);
        ListNode node2 = new ListNode(3);
        ListNode node3 = new ListNode(2);
        ListNode node4 = new ListNode(7);
        ListNode node5 = new ListNode(1);
        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node5;
        System.out.println(object.sortList(node1));
    }
}
