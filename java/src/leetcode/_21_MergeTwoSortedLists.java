package leetcode;

import leetcode.domain.ListNode;

/**
 * author：baixiaoling
 * date: 2017/12/14
 * <p>
 * description:
 */
public class _21_MergeTwoSortedLists {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
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

        if(index1 != null) {
            pre.next = index1;
        }
        if(index2 != null) {
            pre.next = index2;
        }
        return dummy.next;
    }

    public static void main(String[] args) {
        ListNode node1 = new ListNode(1);
        ListNode node1_1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);
        ListNode node4_1 = new ListNode(4);
        node1.next = node2;
        node2.next = node4;
        node1_1.next = node3;
        node3.next = node4_1;
        _21_MergeTwoSortedLists object = new _21_MergeTwoSortedLists();
        System.out.println(object.mergeTwoLists(node1, node1_1));
    }
}
