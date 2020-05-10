package leetcode;

import leetcode.domain.ListNode;

import java.util.HashMap;
import java.util.Map;

/**
 * author：baixiaoling
 * date: 2017/12/29
 * <p>
 * description:
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * <p>
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 * 方法1： 使用一个hashmap保存每个值出现的次数
 * 方法2：使用快慢指针
 */
public class _82_RemoveDuplicatesfromSortedListII {

    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) return head;
        Map<Integer, Integer> map = new HashMap<>();

        ListNode index = head;
        while (index != null) {
            if (map.containsKey(index.val)) {
                map.put(index.val, map.get(index.val) + 1);
            } else {
                map.put(index.val, 1);
            }
            index = index.next;

        }

        ListNode result = new ListNode(-1);
        ListNode dummy = result;
        while (head != null) {
            if (map.get(head.val) == 1) {
                result.next = head;
                result = result.next;

            }
            head = head.next;
        }
        result.next = null;
        return dummy.next;
    }

    /*
    快慢指针
     */
    public ListNode deleteDuplicates2(ListNode head) {
        // fast - to find the last node of dups.

        ListNode dummy = new ListNode(0), fast = head, slow = dummy;
        slow.next = fast;
        while (fast != null) {
            while (fast.next != null && fast.val == fast.next.val) {
                fast = fast.next;    //while loop to find the last node of the dups.
            }
            if (slow.next != fast) { //duplicates detected.
                slow.next = fast.next; //remove the dups.
                fast = fast.next;     //reposition the fast pointer.
            } else { //no dup, move down both pointer.
                slow = slow.next;
                fast = fast.next;
            }

        }
        return dummy.next;
    }


    public static void main(String[] args) {
        _82_RemoveDuplicatesfromSortedListII object = new _82_RemoveDuplicatesfromSortedListII();
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(2);
//        ListNode node4 = new ListNode(3);
//        ListNode node5 = new ListNode(4);
//        ListNode node6 = new ListNode(4);
//        ListNode node7 = new ListNode(5);
        node1.next = node2;
        node2.next = node3;
//        node3.next = node4;
//        node4.next = node5;
//        node5.next = node6;
//        node6.next = node7;
        System.out.println(object.deleteDuplicates(node1));
    }
}
