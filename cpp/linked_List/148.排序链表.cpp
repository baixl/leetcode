/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 * https://leetcode-cn.com/problems/sort-list/
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
    // 这里要求使用O(nlogn)时间和常数空间， 满足条件的有归并排序和快速排序
    // canhttps://www.cnblogs.com/grandyang/p/4249905.html
    /* 归并排序： 分治法，将链表从中间断开，依次递归排序前后两部分
        1、找到链表中点
        2、断开
        3、merge：归并排序
    */
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;  //断开原来的链表

        return merge(sortList(head), sortList(slow));
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);  // 这儿也使用递归调用
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
    ListNode* merge2(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode* new_head = new ListNode(-1);
        ListNode* same_head = new_head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                new_head->next = l1;
                l1 = l1->next;
            } else {
                new_head->next = l2;
                l2 = l2->next;
            }
            new_head = new_head->next;
        }
        if (l1) new_head->next = l1;
        if (l2) new_head->next = l2;
        return same_head->next;
    }

    // 快速排序
    ListNode* sortList2(ListNode* head) {
        quickSort(head, nullptr);
        return head;
    }

    void quickSort(ListNode* head, ListNode* tail) {
        if (head == tail || head->next == nullptr) {
            return;
        }

        ListNode* mid = partition(head, tail);

        quickSort(head, mid);
        quickSort(mid->next, tail);
    }
    // TODO:
    ListNode* partition(ListNode* head, ListNode* tail) {
        int pivot = head->val;
        ListNode* s = head;
        ListNode* cur = head->next;
        while (cur != nullptr && cur != tail) {
            if (cur->val < pivot) {
                s = s->next;
                swap(s, cur);
            }
            cur = cur->next;
        }
        swap(s, head);
        return s;
    }

    void swap(ListNode* a, ListNode* b) {
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
    }
};
