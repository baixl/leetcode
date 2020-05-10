/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] å›žæ–‡é“¾è¡¨
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
    // O(n)时间和O(1)空间
    //  思路：快慢指针 1、先找到链表的中点  2、后半部分就地反转  3、
    //  比较前后两部分是否相同
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        ListNode* mid = find_mid(head);
        cout<< mid->val<<endl;
        mid = reverse(mid);
        ListNode* p = head;
        ListNode* q = mid;
        while (p != nullptr && q != nullptr && p->val == q->val) {
            p = p->next;
            q = q->next;
        }
        if (q == nullptr) {
            return true;
        }
        return false;
    }
    // 找到后半部分，注意奇偶长度的边界
    ListNode* find_mid(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast !=nullptr && fast->next == nullptr) { // 偶数
            slow = slow->next;
        } 
        return slow;
    }
    // 递归反转
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
       ListNode* new_head = reverse(head->next);  // 1、 先反转后面的节点
            head->next->next = head;      // 将后一个链表指向前一个
            head->next = nullptr;  // 前一个指向后一个节点的指针断开
            return new_head;       // 返回新的链表头
    }
};
