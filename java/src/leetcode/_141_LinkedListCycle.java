package leetcode;

import leetcode.domain.ListNode;

/**
 * author：baixiaoling
 * date: 2017/12/30
 * <p>
 * description:
 * 判断链表是否有环
 */
public class _141_LinkedListCycle {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) return false;

        ListNode fast = head;
        ListNode slow = head;

        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow) {
                return true;
            }
        }
        return false;

    }
}
