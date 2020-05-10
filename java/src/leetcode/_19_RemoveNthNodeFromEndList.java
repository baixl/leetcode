package leetcode;

import leetcode.domain.ListNode;

/**
 * author：baixiaoling
 * date: 2017/12/14
 * <p>
 * description:
 */


public class _19_RemoveNthNodeFromEndList {


    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null || head.next == null) {
            return null;
        }

        ListNode start = new ListNode(0);
        start.next = head;
        ListNode index = new ListNode(0);
        index.next = start;
        int length = 0;
        while (start != null) {
            length++;
            start = start.next;
        }
        length--;
        start = index.next;
        int count = 0;
        while (start != null) {
            count++;
            ListNode node = start.next;
            if (count == length - n + 1) {
                if (node == null) {
                    start = null;
                } else {
                    start.next = start.next.next;
                }
                break;
            }
            start = start.next;
        }
        return index.next.next;
    }

    public static void main(String[] args) {
        //1->2->3->4->5
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
//        ListNode node3 = new ListNode(3);
//        ListNode node4 = new ListNode(4);
//        ListNode node5 = new ListNode(5);
        node1.next = node2;
//        node2.next = node3;
//        node3.next = node4;
//        node4.next = node5;
        _19_RemoveNthNodeFromEndList object = new _19_RemoveNthNodeFromEndList();
        System.out.println(object.removeNthFromEnd(node1, 2));

    }
}
