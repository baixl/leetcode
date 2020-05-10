/*
 * [206] 反转链表
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 * Easy (64.38%)
 * 反转一个单链表。
 * 示例:
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
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
    方法1： 递归
    */
    ListNode* reverseList2(ListNode* head) {
        if (nullptr == head || nullptr == head->next) return head;

        ListNode* new_head = reverseList2(head->next);  // 新链表的头结点

        head->next->next = head;  // 将后一个链表指向前一个
        head->next = nullptr;     // 前一个指向后一个节点的指针断开
        return new_head;
    }
    /*
    方法2： 迭代
    利用两个结点指针和一个中间结点指针temp(用来记录当前结点的下一个节点的位置)，分别指向当前结点和前一个结点，
    每次循环让当前结点的指针域指向前一个结点即可，翻转结束后，记得将最后一个节点的链域置为空。
    1、1(pre) -> 2(cur) -> 3(cur->next) ->4 -> 5]
    2、1(pre) -> 2(cur) -> 3(end = cur->next) ->4 -> 5]
    3、1(pre) <- 2(cur) -> 3(end ) ->4 -> 5]
    3、1 <- 2(pre= cur) -> 3(end) ->4 -> 5]
    3、1 <- 2(pre) -> 3(cur) ->4 -> 5]
    */
    ListNode* reverseList(ListNode* head) {
        if (nullptr == head || nullptr == head->next) return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* end = head->next->next;
        while (cur) {
            end = cur->next;
            cur->next = pre;
            pre = cur;
            cur = end;
        }
        head->next = nullptr;
        return pre;
    }
};
