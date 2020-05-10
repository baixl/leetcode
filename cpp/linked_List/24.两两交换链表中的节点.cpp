/*
 * [24] 两两交换链表中的节点
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 * Medium (62.18%)
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 示例:
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    /*
     1、定义一个新的头结点 指向head : pre ->1 ->2 ->3 ->4
     2、定义、a b 分别指向 head 和head->next : pre ->1(a) ->2(b) ->3 ->4
     3、交换： pre->next = b
              a->next = b->next
              b->next = a
     4、 往后移动:
              pre = a

    */
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        ListNode* dummy = pre;
        while (pre->next && pre->next->next) {
            ListNode* a = pre->next;
            ListNode* b = pre->next->next;
            pre->next = b;
            a->next = b->next;
            b->next = a;
            pre = a;
        }
        return dummy->next;
    }
};
