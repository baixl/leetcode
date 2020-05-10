/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    1、快慢指针 fast slow，开始时fast 移动两步， slow每次移动一步。 若fast 与slow相遇则有环
    2、如何求环的起点呢， 当相遇时，fast移动到head， fast和slow 同步移动(每次移动1步)相遇的点即为环的入口
    说明：https://blog.csdn.net/wuzhekai1985/article/details/6725263
    假设：head到环的入口距离 x， 环入口到 快慢指针交点为y，  环的周长为 r
    则相遇时：slow步长为s， fast步长为2s，则有
    x+y = s
    s+nr =2s

    ==> s=nr x+y =nr  x =nr-y
    即 从相遇点走到环入口 与从起点走到换入口一定相差 n圈， 将fast移动到head， 同步移动两个指针，则相遇的点一定在环的入口
    */
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                break;
            }
        }
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
