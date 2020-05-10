package leetcode;

import leetcode.domain.ListNode;

/**
 * author：baixiaoling
 * date: 2017/12/30
 * <p>
 * description:
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * <p>
 * Note: Do not modify the linked list.
 * <p>
 * Follow up:
 * Can you solve it without using extra space?
 * <p>
 * 解题思路见：http://blog.csdn.net/wuzhekai1985/article/details/6725263
 * <p>
 * 具体做法：
 * 1 使用快慢指针 fast 和 slow   fast每次移动两步，slow每次移动一步，当相遇时，说明有环
 * 2 将fast移动到链表头，然后fast和slow同步移动，知道再次相遇的点，就是环的入口
 */
public class _142_LinkedListCycleII {
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null) return null;
        ListNode fast = head;
        ListNode slow = head;

        boolean hasCycle = false;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow) {
                hasCycle = true;
                break;
            }
        }
        if (!hasCycle) return null; // 无环，直接返回false
        fast = head;
        while (fast != slow) {
            fast = fast.next;
            slow = slow.next;
        }
        return fast;
    }

    public static void main(String[] args) {
        _142_LinkedListCycleII object = new _142_LinkedListCycleII();
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);
        ListNode node5 = new ListNode(5);
        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node5;
        node5.next = node2;
        System.out.println(object.detectCycle(node1).val);
    }

}
