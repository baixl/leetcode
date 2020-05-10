/*
 * [61] 旋转链表
 * https://leetcode-cn.com/problems/rotate-list/description/
 * Medium (38.96%)
 * 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 * 示例 1:
 * 输入: 1->2->3->4->5->NULL, k = 2
 * 输出: 4->5->1->2->3->NULL
 * 解释:
 * 向右旋转 1 步: 5->1->2->3->4->NULL
 * 向右旋转 2 步: 4->5->1->2->3->NULL
 * 示例 2:
 * 输入: 0->1->2->NULL, k = 4
 * 输出: 2->0->1->NULL
 * 解释:
 * 向右旋转 1 步: 2->0->1->NULL
 * 向右旋转 2 步: 1->2->0->NULL
 * 向右旋转 3 步: 0->1->2->NULL
 * 向右旋转 4 步: 2->0->1->NULL
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
    1、 计算 链表长度
    2、找到链表分割点（从head 向右遍历 len -k +1个位置）
    3、将右侧链表连到head上
    4、返回右侧链表的头
     */
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k <= 0) return head;
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        k %= len;
        if (k == 0) return head;

        ListNode* node = head;

        k = len - k;
        while (node && k > 1) {
            node = node->next;
            k--;
        }
        ListNode* new_head = node->next;
        ListNode* dummy = node->next;

        node->next = nullptr;
        while (dummy->next) {
            dummy = dummy->next;
        }
        dummy->next = head;
        return new_head;
    }
};
