/*
 * [25] K 个一组翻转链表
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 * Hard (54.56%)
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 示例 :
 * 给定这个链表：1->2->3->4->5
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 说明 :
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
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
    方法1：依次截断链表并翻转
    方法2： 边遍历边翻转
    这里实现方法1
    */
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k <= 1) return head;
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        ListNode* dummy = pre;
        ListNode* end = dummy;

        while (end->next != nullptr) {
            for (auto i = 0; i < k && end != nullptr; i++) {
                end = end->next;
            }
            if (end == nullptr) break;

            ListNode* start = pre->next;
            ListNode* next = end->next;

            end->next = nullptr;
            pre->next = reverse(start);
            start->next = next;
            pre = start;
            end = pre;
        }
        return dummy->next;
    }
    // 翻转一个链表
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* pre = nullptr;
        // pre->next = head;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
