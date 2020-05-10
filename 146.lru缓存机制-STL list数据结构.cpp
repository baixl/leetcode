/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 *
 * https://leetcode-cn.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (46.47%)
 * Likes:    479
 * Dislikes: 0
 * Total Accepted:    43.8K
 * Total Submissions: 93.6K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
 * 
 * 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
 * 写入数据 put(key, value) -
 * 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 * 
 * 进阶:
 * 
 * 你是否可以在 O(1) 时间复杂度内完成这两种操作？
 * 
 * 示例:
 * 
 * LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // 返回  1
 * cache.put(3, 3);    // 该操作会使得密钥 2 作废
 * cache.get(2);       // 返回 -1 (未找到)
 * cache.put(4, 4);    // 该操作会使得密钥 1 作废
 * cache.get(1);       // 返回 -1 (未找到)
 * cache.get(3);       // 返回  3
 * cache.get(4);       // 返回  4
 * 
 * 
 */

// @lc code=start
/****************************************
* 设计LRU， 需要实现的操作：
获取数据get，和写入数据put O(1)时间实现， 即插入、查找、更新都需要O(1)的时间
什么样的数据结构能满足这些需求呢？

1、先看查找， O(1)时间查找可以用hash结构，但数据无固定顺序，不便于移动和删除
2、要插入和删除较快： 链表，但链表查找时间是O(n)
这里， 结合hash和链表的结构，形成一种新的数据结构：hash链表

LRU的核心数据结构就是哈希链表: 双向链表+hash （双向链表可以方便执行插入和删除，删除操作需要知道当前节点的前一个节点，需要双向这种特征）
思路就是赋予链表快速查找的能力: 可以快速查找某个key是否在链表（hash的特性）中，同时可以快速实现删除、插入的操作（链表的特性）


双向链表可以用stl中的list结构， 也可以自己实现：

高票答案：https://leetcode-cn.com/problems/lru-cache/solution/lru-ce-lue-xiang-jie-he-shi-xian-by-labuladong/

list+hash：https://leetcode-cn.com/problems/lru-cache/solution/ha-xi-shuang-xiang-lian-biao-you-hua-ban-ben-by-to/
自己实现数据结构+hash： https://leetcode-cn.com/problems/lru-cache/solution/c-unordered_maphe-zi-ji-xie-de-shuang-xiang-lian-b/


我这里先用自己实现的数据结构实现一遍， 然后使用list数据结构再实现一遍

***************************************/
class LRUCache {
public:
    int size = 0;
    int capacity;
    std::list<pair<int, int>> doublelist; // 存储key value的双向链表
    unordered_map<int, list<pair<int, int>>::iterator> map;// 哈希表，key映射到双向链表的节点(key, value)


    LRUCache(int _capacity) {
        capacity = _capacity;
        size = 0;
    }
    
    int get(int key) {
        if (map.count(key) == 0) return -1;
        pair<int, int> kv = *map[key];

        doublelist.erase(map[key]);
        doublelist.push_front(kv);
        map[key] = doublelist.begin();
        return kv.second;
    }
    
    void put(int key, int value) {
        if (map.count(key) == 1) { // 只更新对应节点的位置
            doublelist.erase(map[key]);
            doublelist.push_front(pair<int, int>(key, value));
            map[key] = doublelist.begin();
        } else {
            if (size < capacity) {// 缓存大小可以放下，将当前节点放到链表头
                doublelist.push_front(pair<int, int>(key, value));
                map[key] = doublelist.begin();
                size++;
            
            } else {// 缓存大小放不下， 删除尾节点， 并将道歉节点放到链表头
               
                map.erase(doublelist.back().first);
                doublelist.pop_back();
                doublelist.push_front(pair<int, int>(key, value));
                map[key] = doublelist.begin();
            }
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end


