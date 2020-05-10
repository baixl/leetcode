package leetcode;

import leetcode.domain.ListNode;

/**
 * author：baixiaoling
 * date: 2017/12/16
 * <p>
 * description:
 */
public class _24_SwapNodesinPairs {
    /*
    https://skyyen999.gitbooks.io/-leetcode-with-javascript/content/questions/24md.html
     */
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode pre = dummy;
        ListNode current = head;
        ListNode nextKeep = null;
        while (current != null && current.next != null) {
            nextKeep = current.next.next;

            current.next.next = current;
            pre.next = current.next;
            current.next = nextKeep;

            pre = current;
            current = current.next;
        }
        return dummy.next;
    }

    public static void main(String[] args) {
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);
        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        _24_SwapNodesinPairs object = new _24_SwapNodesinPairs();
        object.swapPairs(node1);
    }
}
