/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (52.65%)
 * Likes:    119
 * Dislikes: 0
 * Total Accepted:    14.8K
 * Total Submissions: 28K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 *
 * 你应当保留两个分区中每个节点的初始相对位置。
 *
 * 示例:
 *
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5
 *
 *
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
    // 方法1： 生成两个链表实现
    ListNode* partition1(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* h1 = new ListNode(-1);
        ListNode* h1_head = h1;
        ListNode* h2 = new ListNode(-1);
        ListNode* h2_head = h2;
        ListNode* cur = head;
        while (cur != nullptr) {
            if (cur->val < x) {
                h1->next = cur;
                h1 = h1->next;
            } else {
                h2->next = cur;
                h2 = h2->next;
            }
            cur = cur->next;
        }
        h1->next = h2_head->next;
        h2->next = nullptr;
        return h1_head->next;
    }
    // 方法2：
    ListNode* partition(ListNode* head, int x) {}
};
