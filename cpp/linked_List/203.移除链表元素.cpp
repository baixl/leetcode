/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (42.30%)
 * Likes:    284
 * Dislikes: 0
 * Total Accepted:    38.3K
 * Total Submissions: 90.4K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 *
 * 示例:
 *
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        ListNode* node = new ListNode(INT_MAX);
        node->next = head;
        ListNode* dummy = node;
        ListNode* cur = node->next;
        while (cur) {
            if (cur->val == val) {
                dummy->next = dummy->next->next;
                cur = cur->next;
            } else {
                dummy = dummy->next;
                cur = cur->next;
            }
        }

        return node->next;
    }
};
