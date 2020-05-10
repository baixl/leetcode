package leetcode;

import leetcode.domain.ListNode;

/**
 * author：baixiaoling
 * date: 2017/12/29
 * <p>
 * description:
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 * Example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 * 解题方法：
 * 首先找到倒数第k个位置，和最后的位置，
 * 将最后位置的next指向头结点
 * 在倒数第k个位置断开
 */
public class _61_RotateList {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k <= 0) return head;
        ListNode fast = head;
        ListNode slow = new ListNode(-1);
        slow.next = fast;
        ListNode index = head;
        int size = 0;
        while (index != null) {
            index = index.next;
            size++;
        }
        // 关键一步
        k = k % size;
        if (k == 0) return head;

        int i = 0;
        ListNode start = null;
        while (fast != null && fast.next != null) {
            if (i < size - k) {
                fast = fast.next;
                slow = slow.next;
                i++;
                start = fast;
            } else {
                fast = fast.next;
            }
        }
        fast.next = head;
        slow.next = null;
        return start;
    }

    public static void main(String[] args) {
        _61_RotateList object = new _61_RotateList();
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);
        ListNode node5 = new ListNode(5);
        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node5;
        System.out.println(object.rotateRight(node1, 4));
    }
}
