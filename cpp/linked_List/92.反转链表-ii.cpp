/*
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * Medium (46.61%)
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 * 示例:
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (nullptr == head || nullptr == head->next) return head;
        if (m >= n) return head;
        ListNode* h = new ListNode(-1);
        h->next = head;

        ListNode* pre = h;
        ListNode* cur = head;
        auto i = 1;
        for (; i < m; i++) {
            pre = pre->next;
            cur = cur->next;
        }

        ListNode* node1 = pre;
        ListNode* node2 = cur;
        for (; i <= n && cur != nullptr; i++) {
            ListNode* end = cur->next;
            cur->next = pre;
            pre = cur;
            cur = end;
        }
        node1->next = pre;
        node2->next = cur;
        return h->next;
    }
};
