/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || n <= 0) {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && n > 0) {
            fast = fast->next;
            n--;
        }
        if (fast == nullptr) {  // 删除的是头部节点
            return head->next;
        }

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return head;
    }
};
