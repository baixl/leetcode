package leetcode;


import leetcode.domain.ListNode;

/**
 * author：baixiaoling
 * date: 2017/12/22
 * <p>
 * description:
 */
public class _83_RemoveDuplicatesfromSortedList {

    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode pre = new ListNode(0);
        pre.next = head;
        while (head != null) {
            if (head.next != null && head.val == head.next.val) {
                head.next = head.next.next;
                continue;
            }
            head = head.next;
        }
        return pre.next;
    }

    public static void main(String[] args) {
        _83_RemoveDuplicatesfromSortedList object = new _83_RemoveDuplicatesfromSortedList();
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(1);
        ListNode node3 = new ListNode(1);
        ListNode node4 = new ListNode(3);
        ListNode node5 = new ListNode(3);
        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node5;
        System.out.println(object.deleteDuplicates(node1));
    }
}
