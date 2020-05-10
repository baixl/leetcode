package leetcode;

import leetcode.domain.ListNode;

/**
 * author：baixiaoling
 * date: 2018/1/8
 * description:
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 * For example, the following two linked lists:
 * A:          a1 → a2->c1 → c2 → c3
 * B:     b1 → b2 → b3->c1 → c2 → c3
 * begin to intersect at node c1.
 * Notes:
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 * Credits:
 * Special thanks to @stellari for adding this problem and creating all test cases.
 * 解题思路：
 * 1 扫描两个链表，统计两个链表的长度
 * 2 将长度较长的链表去掉多余的部分
 * 3 从相同长度开始往终点遍历，直到最后一个节点
 */
public class _160_IntersectionofTwoLinkedLists {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) return null;
        ListNode p1 = headA;
        ListNode p2 = headB;

        int length1 = 1;
        int length2 = 1;
        while (p1.next != null) {
            length1++;
            p1 = p1.next;
        }
        while (p2.next != null) {
            length2++;
            p2 = p2.next;
        }
        if (p1.val != p2.val) return null;
        p1 = headA;
        p2 = headB;
        if (length1 != length2) {

            int count = 0;
            if (length1 > length2) {
                while (count < Math.abs(length1 - length2)) {
                    count++;
                    p1 = p1.next;
                }
            } else {
                while (count < Math.abs(length1 - length2)) {
                    count++;
                    p2 = p2.next;
                }
            }

        }
        while (p1 != null && p1 != p2) {
            p1 = p1.next;
            p2 = p2.next;
        }
        return p1;
    }

    public static void main(String[] args) {
        _160_IntersectionofTwoLinkedLists object = new _160_IntersectionofTwoLinkedLists();
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);
        ListNode node5 = new ListNode(5);
        ListNode node6 = new ListNode(6);
//        ListNode node7 = new ListNode(7);
        node1.next = node2;
        node2.next = node3;
        node3.next = node5;
        node5.next = node6;
        node4.next = node5;
        System.out.println(object.getIntersectionNode(node1, node4));
    }
}
