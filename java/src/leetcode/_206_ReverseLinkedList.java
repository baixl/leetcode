package leetcode;

import leetcode.domain.ListNode;

import java.util.ArrayList;
import java.util.List;

/**
 * author：baixiaoling
 * date: 2017/12/28
 * <p>
 * description:
 * 题目描述：描述leetcode题目
 * Reverse a singly linked list.
 * <p>
 * click to show more hints.
 * <p>
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 * 解题思路：
 * 方法1 ： 遍历链表，记录每个节点的数字，然后尾部重建链表，时间O(n)  空间O(n)
 * <p>
 * 方法2：原地翻转： http://blog.csdn.net/nomasp/article/details/50514593
 * 画图说明了如何进行原地翻转
 */
public class _206_ReverseLinkedList {
    public ListNode reverseList(ListNode head) {
        if (head == null) return null;
        ListNode pre = new ListNode(-1);
        ListNode dumy = pre;
        List<Integer> list = new ArrayList<>();
        while (head != null) {
            list.add(head.val);
            head = head.next;
        }
        for (int i = list.size() - 1; i >= 0; i--) {
            ListNode node = new ListNode(list.get(i));
            pre.next = node;
            pre = pre.next;
        }
        return dumy.next;
    }

    public ListNode reverseList2(ListNode head) {
        if (head == null) return null;

        ListNode newHead = null;
        ListNode current = head;
        while (current != null) {
            ListNode nextNode = current.next;
            current.next = newHead;
            newHead = current;
            current = nextNode;
        }
        return newHead;
    }

    public static void main(String[] args) {
        _206_ReverseLinkedList object = new _206_ReverseLinkedList();
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        node1.next = node2;
        node2.next = node3;
        System.out.println(object.reverseList2(node1));
    }
}
