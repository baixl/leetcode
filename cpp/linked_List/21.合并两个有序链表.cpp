/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        };

        ListNode* head = new ListNode(-1);
        ListNode* dummy = head;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                head->next = l1;
                head = head->next;
                l1 = l1->next;
            } else {
                head->next = l2;
                head = head->next;
                l2 = l2->next;
            }
        }

        if (l1 != nullptr) {
            head->next = l1;
        }
        if (l2 != nullptr) {
            head->next = l2;
        }
        return dummy->next;
    }
};
