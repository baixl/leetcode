package leetcode;

import leetcode.domain.ListNode;

import java.util.ArrayList;
import java.util.List;

/**
 * author：baixiaoling
 * date: 2017/12/27
 * <p>
 * description:
 * 题目描述：
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * return 1->4->3->2->5->NULL.
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 * <p>
 * 解题思路：
 * 方法1 ： 遍历数组，重建链表
 * 方法2：分为两个步骤，第一步是找到m结点所在位置，第二步就是进行反转直到n结点。
 * 反转的方法就是每读到一个结点，把它插入到m结点前面位置，然后m结点接到读到结点的下一个。
 * 总共只需要一次扫描，所以时间是O(n)，只需要几个辅助指针，空间是O(1)
 */
public class _92_ReverseLinkedListII {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (head == null || m >= n) return head;
        List<Integer> list = new ArrayList<>();
        while (head != null) {
            list.add(head.val);
            head = head.next;
        }
        ListNode pre = new ListNode(-1);
        ListNode dummy = pre;
        for (int i = 0; i < m - 1; i++) {
            pre.next = new ListNode(list.get(i));
            pre = pre.next;
        }
        for (int i = m - 1; i < n; i++) {
            pre.next = new ListNode(list.get(n - 1 - (i - m + 1)));
            pre = pre.next;
        }
        for (int i = n; i < list.size(); i++) {
            pre.next = new ListNode(list.get(i));
            pre = pre.next;
        }
        return dummy.next;
    }

    public ListNode reverseBetween2(ListNode head, int m, int n) {
        if (head == null || m >= n) return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode preNode = dummy;
        int i = 1;
        while (preNode.next != null && i < m) {
            preNode = preNode.next;
            i++;
        }
        if (i < m)
            return head;
        ListNode mNode = preNode.next;
        ListNode cur = mNode.next;
        while (cur != null && i < n) {
            ListNode next = cur.next;
            cur.next = preNode.next;
            preNode.next = cur;
            mNode.next = next;
            cur = next;
            i++;
        }
        return dummy.next;
    }

    public static void main(String[] args) {
        _92_ReverseLinkedListII object = new _92_ReverseLinkedListII();
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);
        ListNode node5 = new ListNode(5);
        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node5;
        System.out.println(object.reverseBetween(node1, 2, 4));

    }


}
