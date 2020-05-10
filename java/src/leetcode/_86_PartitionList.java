package leetcode;

import leetcode.domain.ListNode;

/**
 * author：baixiaoling
 * date: 2017/12/29
 * <p>
 * description:
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * <p>
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * <p>
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 */
public class _86_PartitionList {
    public ListNode partition(ListNode head, int x) {
        if (head == null || head.next == null) return head;
        ListNode litter = new ListNode(-1);
        ListNode bigger = new ListNode(-1);
        ListNode litterDummy = litter;
        ListNode biggerDummy = bigger;

        while (head != null) {
            if (head.val < x) {
                litter.next = head;
                litter = litter.next;
            } else {
                bigger.next = head;
                bigger = bigger.next;
            }

            head = head.next;

        }

//        System.out.println(litter);
//        System.out.println(bigger);
        litter.next = biggerDummy.next;
        bigger.next = null;
//        System.out.println(litterDummy.next);
//        System.out.println(biggerDummy.next);
        return litterDummy.next;
    }

    public static void main(String[] args) {
        _86_PartitionList object = new _86_PartitionList();
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(4);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(2);
        ListNode node5 = new ListNode(5);
        ListNode node6 = new ListNode(2);
        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node5;
        node5.next = node6;
        System.out.println(object.partition(node1, 3));
    }
}
