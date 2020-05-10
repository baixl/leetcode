/*
 * [23] 合并K个排序链表
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 * algorithms
 * Hard (47.29%)
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 示例:
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
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
    /*
    方法1：两两合并
    */
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        ListNode* pre = nullptr;
        for (auto i = 0; i < lists.size(); i++) {
            pre = merge(pre, lists[i]);
        }
        return pre;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        if (l1->val > l2->val) {
            return merge(l2, l1);
        }
        ListNode* head = new ListNode(-1);
        ListNode* dummy = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
                head = head->next;
            } else {
                head->next = l2;
                l2 = l2->next;
                head = head->next;
            }
        }
        if (l1) head->next = l1;
        if (l2) head->next = l2;
        return dummy->next;
    }

    /*
   方法2：将所有链表元素放到一个数组中， 对数组排序，然后修改new指针即可
   */
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];
        vector<ListNode*> vec;
        for (auto i = 0; i < lists.size(); i++) {
            ListNode* head = lists[i];
            while (head) {
                vec.push_back(head);
                head = head->next;
            }
        }
        sort(vec.begin(), vec.end(), [](auto x, auto y) { return x->val < y->val; });
        if (vec.size() == 0) return nullptr;
        for (auto i = 0; i < vec.size() - 1; i++) {
            vec[i]->next = vec[i + 1];
        }
        vec[vec.size() - 1]->next = nullptr;
        return vec[0];
    }

    /*
  方法3：归并排序
  */
    ListNode* merge(vector<ListNode*>& lists, int begin, int end) {
        if (begin > end) return nullptr;
        if (begin == end) return lists[begin];
        int mid = begin + (end - begin) / 2;
        ListNode* left = merge(lists, begin, mid);
        ListNode* right = merge(lists, mid + 1, end);
        ListNode* head = new ListNode(-1);
        ListNode* dummy = head;
        while (left && right) {
            if (left->val < right->val) {
                head->next = left;
                left = left->next;
                head = head->next;
            } else {
                head->next = right;
                right = right->next;
                head = head->next;
            }
        }
        if (left) head->next = left;
        if (right) head->next = right;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) { 
        return merge(lists, 0, lists.size() - 1); 
    }
};
