/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0;
        int lengthB = 0;
        ListNode *temp_A = headA;
        while (temp_A != nullptr) {
            temp_A = temp_A->next;
            lengthA++;
        }

        ListNode *temp_B = headB;
        while (temp_B != nullptr) {
            temp_B = temp_B->next;
            lengthB++;
        }
        temp_A = headA;
        temp_B = headB;
        if (lengthA > lengthB) {
            int count = lengthA - lengthB;
            while (count > 0) {
                temp_A = temp_A->next;
                count--;
            }
        }
        if (lengthA < lengthB) {
            int count = lengthB - lengthA;
            while (count > 0) {
                temp_B = temp_B->next;
                count--;
            }
        }
        while (temp_A != nullptr && temp_B != nullptr) {
            if (temp_A == temp_B) {
                return temp_A;
            } else {
                temp_A = temp_A->next;
                temp_B = temp_B->next;
            }
        }
        return temp_A;
    }
};
