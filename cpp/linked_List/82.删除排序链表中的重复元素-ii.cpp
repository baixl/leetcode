/*
 * [82] 删除排序链表中的重复元素 II
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/
 * Medium (43.69%)
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
 * 示例 1:
 * 输入: 1->2->3->3->4->4->5
 * 输出: 1->2->5
 * 示例 2:
 * 输入: 1->1->1->2->3
 * 输出: 2->3
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
    1新建一个新的头结点，指向head
    */
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        ListNode* dummy = pre;
        ListNode* cur = head;
        while (cur) {
            bool flag = false;  // 是否有重复节点
            while (cur->next && cur->val == cur->next->val) {
                flag = true;
                cur = cur->next;
            }
            if (!flag) {
                pre->next = cur;
                pre = pre->next;
            } else {
                pre->next = cur->next;
            }
             cur =cur->next;
        }
        return dummy ->next;
    }
};
