package leetcode;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;

/**
 * author：baixiaoling
 * date: 2017/12/23
 * <p>
 * description:
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 * <p>
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * <p>
 * 解法：使用双向链表+hash表的结构，
 * 1 hash表存放每个节点的key 和对应节点， 通过O(1)查询节点，
 * 2 使用双向链表，是删除和添加节点的时间也为O(1)
 */
public class _146_LRUCache {

    private class ListNode {
        // 双向链表 的数据结构
        ListNode pre;
        ListNode next;
        int key;
        int val;

        public ListNode(int k, int v) {
            key = k;
            val = v;
            this.next = null;
            this.pre = null;
        }
    }


    int capacity;

    Map<Integer, ListNode> map = new HashMap<>();
    ListNode head = null;
    ListNode tail = null;

    public _146_LRUCache(int capacity) {
        this.capacity = capacity;
    }

    public int get(int key) {
        if (!map.containsKey(key)) return -1;
        ListNode node = map.get(key);
        removeNode(node);
        setHead(node);
        return node.val;
    }

    // 需要判断是否为头尾节点
    private void removeNode(ListNode node) {
        // 头
        if (node.pre != null) {
            node.pre.next = node.next;
        } else {
            head = node.next;
        }
        if (node.next != null) {
            node.next.pre = node.pre;
        } else {
            tail = node.pre;
        }
    }

    private void setHead(ListNode node) {
        node.next = head;
        node.pre = null;
        if (head != null) {
            head.pre = node;
        }
        head = node;
        if (tail == null) {
            tail = head;
        }
    }

    public void put(int key, int value) {
        if (map.containsKey(key)) {
            ListNode oldNode = map.get(key);
            oldNode.val = value;
            removeNode(oldNode);
            setHead(oldNode);
        } else {
            ListNode newNode = new ListNode(key, value);
            if (map.size() >= capacity) {
                map.remove(tail.key);
                removeNode(tail);
                setHead(newNode);
            } else {
                setHead(newNode);
            }
            map.put(key, newNode);
        }
    }


    public static void main(String[] args) {
        _146_LRUCache cache = new _146_LRUCache(2);
        cache.put(1, 1);
        cache.put(2, 2);
        System.out.println();
        System.out.println(cache.get(1));
        cache.put(3, 3);
        System.out.println(cache.get(2));
        cache.put(4, 4);
        System.out.println(cache.get(1));
        System.out.println(cache.get(3));
        System.out.println(cache.get(4));
    }
}
