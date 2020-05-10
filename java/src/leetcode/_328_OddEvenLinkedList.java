package leetcode;

import leetcode.domain.ListNode;

/**
 * author：baixiaoling
 * date: 2018/1/20
 * <p>
 * description:
 * Given a singly linked list, group all odd nodes together followed by the even nodes.
 * Please note here we are talking about the node number and not the value in the nodes.
 * <p>
 * You should try to do it in place. The program should run in O(1) space complexity and
 * O(nodes) time complexity.
 * <p>
 * Example:
 * Given 1->2->3->4->5->NULL,
 * return 1->3->5->2->4->NULL.
 * <p>
 * Note:
 * The relative order inside both the even and odd groups should remain as it was in the input.
 * The first node is considered odd, the second node even and so on ...
 * <p>
 * Credits:
 * Special thanks to @DjangoUnchained for adding this problem and creating all test cases.
 */
public class _328_OddEvenLinkedList {
    /*
    使用两个指针，pre指向奇节点，current指向偶节点
    然后把偶节点cur后面的那个奇节点提前到pre的后面
    然后pre和cur各自前进一步，此时cur又指向偶节点，pre指向当前奇节点的末尾
     */
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode pre = head, current = head.next;
        while (current != null && current.next != null) {
            ListNode temp = pre.next;
            pre.next = current.next;
            current.next = current.next.next;
            pre.next.next = temp;

            pre = pre.next;
            current = current.next;
        }
        return head;
    }
}
