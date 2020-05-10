/*
 * [138] 复制带随机指针的链表
 * https://leetcode-cn.com/problems/copy-list-with-random-pointer/description/
 * Medium (37.05%)
 * '{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}'
 *
 * 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
 *
 * 要求返回这个链表的深拷贝。 
 *
 * 示例：
 * 输入：
 * {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
 * 解释：
 * 节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
 * 节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。
 *
 * 提示：
 * 你必须返回给定头的拷贝作为对克隆列表的引用。
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        Node* node = head;
        // 1、将原节点复制到next
        while (node != nullptr) {
            Node* copy = new Node(node->val, nullptr, nullptr);
            copy->next = node->next;
            node->next = copy;
            node = copy->next;
        }
        // 2、复制random
        node = head;
        while (node != nullptr) {
            if (node->random != nullptr) {
                node->next->random = node->random->next;
            }
            node = node->next->next;
        }
        // 分裂链表
        node = head;
        Node* newHead = node->next;
        Node* newNode = newHead;
        while (node != nullptr) {
            node->next = node->next->next;
            if (newNode->next != nullptr) {
                newNode->next = newNode->next->next;
            }
            node = node->next;
            newNode = newNode->next;
        }
        return newHead;
    }
};
