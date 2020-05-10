package leetcode;

import javafx.scene.control.RadioMenuItem;
import leetcode.domain.RandomListNode;

import java.util.HashMap;
import java.util.Map;

/**
 * author：baixiaoling
 * date: 2018/1/11
 * <p>
 * description:
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 * <p>
 * Return a deep copy of the list.
 * 解题思路：
 * 由于每个节点有指向下一个节点 和一个指向任意节点的random指针，深拷贝时有两种方式
 * 1 第一种方法：比较传统，用一个hash表保存random，遍历后从hash表中恢复random
 * 2 第二种方法：将每个random指针保存在每个节点后面
 */
public class _138_CopyListwithRandomPointer {
    /*
    方法1： 使用hash表实现
    1 使用hashmap。 key为原链表节点指针，val为新链表节点指针
    第一种方法，就是使用HashMap来坐，HashMap的key存原始pointer，value存新的pointer。
    第一轮遍历： 只拷贝数值来建立链表， 同时在hashmap中维持新旧poniter的对应关系，
    第二轮遍历，复制random的值。第一遍已经把链表的对应关系存放在了hashmap中，只需将旧节点的random 作为key，取中val赋值给
    new node的random
     */
    public RandomListNode copyRandomList(RandomListNode head) {
        if (head == null) return null;
        //todo
        Map<RandomListNode, RandomListNode> map = new HashMap<>();
        RandomListNode newHead = new RandomListNode(head.label);
        map.put(head, newHead);
        RandomListNode oldPointer = head.next;
        RandomListNode newPointer = newHead;
        while (oldPointer != null) {
            RandomListNode newNode = new RandomListNode(oldPointer.label);
            map.put(oldPointer, newNode);
            newPointer.next = newNode;

            oldPointer = oldPointer.next;
            newPointer = newPointer.next;
        }
        oldPointer = head;
        newPointer = newHead;
        while (oldPointer != null) {
            newPointer.random = map.get(oldPointer.random);
            newPointer = newPointer.next;
            oldPointer = oldPointer.next;
        }

        return newHead;
    }


    /*
    方法1： 不实用hashmap

    1 使用hashmap。 key为原链表节点指针，val为新链表节点指针
    第一种方法，就是使用HashMap来坐，HashMap的key存原始pointer，value存新的pointer。
    第一轮遍历： 只拷贝数值来建立链表， 同时在hashmap中维持新旧poniter的对应关系，
    第二轮遍历，复制random的值。第一遍已经把链表的对应关系存放在了hashmap中，只需将旧节点的random 作为key，取中val赋值给
    new node的random
     */
    public RandomListNode copyRandomList2(RandomListNode head) {
        if (head == null) return null;
        RandomListNode node = head;
        //第一遍，将所有节点复制到当前节点的后面 比如1->2->3->null 变为  1->1->2->2->3->3->null
        while (node != null) {
            RandomListNode newNode = new RandomListNode(node.label);
            newNode.next = node.next;
            node.next = newNode;
            node = newNode.next;
        }
        // 第2遍， 复制random节点
        node = head;
        while (node != null) {
            if (node.random != null) {
                node.next.random = node.random.next; // 指向原始random对应的新节点
            }
            node = node.next.next;
        }
        // 第3遍，断开新旧节点
        RandomListNode newHead = head.next;
        node = head;
        while (node != null) {
            RandomListNode newNode = node.next;
            node.next = newNode.next;

            if (newNode.next != null) {
                newNode.next = newNode.next.next;
            }
            node = node.next;
        }

        return newHead;
    }

    public static void main(String[] args) {
        _138_CopyListwithRandomPointer object = new _138_CopyListwithRandomPointer();
        RandomListNode node = new RandomListNode(-2);
        System.out.println(object.copyRandomList2(node));
    }
}
