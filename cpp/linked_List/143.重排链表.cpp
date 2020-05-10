/*
 * @lc app=leetcode.cn id=143 lang=cpp
 * [143] 重排链表
 * https://leetcode-cn.com/problems/reorder-list/description/
 * Medium (51.62%)
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 示例 1:
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 * 示例 2:
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
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
    1、新建一个pre 节点，pre->next = head
    1、将链表分割： 可以先找到链表的中间节点（注意链表奇偶长度）： 参考876： 单链表的中间节点
    2、将后半段翻转
    3、拼接链表
    */
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;

        ListNode* pre = new ListNode(-1);
        pre->next = head;
        ListNode *slow = pre, *fast = pre;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 后半段的起点就是fast，比如 pre->1->2->3->4， 此时 fast = 4, slow = 2, 后半段是 3->4 (slow ->next)
        // pre->1->2->3->4->5， 此时 fast = null, slow = 3, 后半段是 4->5(slow->next)

        ListNode* left_head = head;
        ListNode* dummy = left_head;
        ListNode* right_head = reverse(slow->next);
        slow->next = nullptr;  // 断开链表

        while (left_head && right_head) {
            ListNode* left_next = left_head->next;
            ListNode* right_next = right_head->next;
            right_head->next = nullptr;
            left_head->next = right_head;
            right_head->next = left_next;

            right_head = right_next;
            left_head = left_next;
        }
    }

    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head->next = nullptr;
        return pre;
    }
};
