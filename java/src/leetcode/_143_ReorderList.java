package leetcode;

import leetcode.domain.ListNode;

/**
 * author：baixiaoling
 * date: 2017/12/30
 * <p>
 * description:
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * <p>
 * You must do this in-place without altering the nodes' values.
 * <p>
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 * 解题方法：
 * 1 中链表中间断开
 * 2 reverse 后半部分
 * 3  合并两个链表
 */
public class _143_ReorderList {
    public void reorderList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null) return;
        ListNode fast = head;
        ListNode slow = head;
        ListNode pre = new ListNode(-1);
        pre.next = slow;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            pre = pre.next;
        }
        // 从slow处断开
        pre.next = null;
//        ListNode left = head;
        ListNode right = reverseList(slow);
        // merge  left 和  right， 当链表长度是奇数时， right会比lefet多一个节点
//        System.out.println(left);
        System.out.println(right);

        ListNode current = head;
        while (current.next != null) {
            ListNode tmp = current.next;
            current.next = right;
            right= right.next;
            current.next.next = tmp;
            current = tmp;
        }
        current.next = right;
        System.out.println(head);
    }

    public ListNode reverseList(ListNode head) {
        if (head == null) return null;

        ListNode pre = null;
        ListNode current = head;
        while (current != null) {
            ListNode temp = current.next;
            current.next = pre;
            pre = current;
            current = temp;
        }
        head = pre;
        return head;
    }


    public static void main(String[] args) {
        _143_ReorderList object = new _143_ReorderList();
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);
        ListNode node5 = new ListNode(5);
        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
//        node4.next = node5;
        object.reorderList(node1);
    }


}
