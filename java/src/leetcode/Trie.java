package leetcode;

import java.util.HashMap;

/**
 * author：baixiaoling
 * date: 2018/1/19
 * <p>
 * description:
 * Implement a trie with insert, search, and startsWith methods.
 * <p>
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 * <p>
 * 实现前缀树
 * <p>
 * 前缀树的原理参考董的博客：http://dongxicheng.org/structure/trietree/
 * https://segmentfault.com/a/1190000003709971
 * <p>
 * Trie树的基本性质可以归纳为：
 * （1）根节点不包含字符，除根节点意外每个节点只包含一个字符。
 * （2）从根节点到某一个节点，路径上经过的字符连接起来，为该节点对应的字符串。
 * （3）每个节点的所有子节点包含的字符串不相同。
 * <p>
 * 前缀树的实现
 * <p>
 * 实现树节点时使用了哈希表来映射字母和子节点的关系
 * insert()：对于插入操作，我们遍历字符串同时，根据上一个节点的哈希表来找到下一个节点，
 * 直到哈希表中没有相应的字母，我们就新建一个节点。
 * 然后从这个新建节点开始，用同样的方法把剩余的字母添加完。
 * 记住最后一个字母要添加叶子节点的标记，表明这个词到此已经完整了。
 * search()：对于搜索操作，我们也是遍历字符串，然后根据每个节点的哈希表找到路径，最后返回该字符串最后一个字母所在节点。
 * 如果中途有找不到路径的情况就直接返回null，如果找到了最后的节点，如果它也是叶子结点的话，就说明找到了。
 * startWith()：使用和search()，一样的方法，只是我们返回的节点不用判断是否是叶子节点。只要找到就行。
 */

class TrieNode {
    HashMap<Character, TrieNode> children = new HashMap<>();
    boolean isLeaf = false;

    char c;

    TrieNode() {

    }

    TrieNode(char c) {
        this.c = c;
    }
}

public class Trie {

    /**
     * Initialize your data structure here.
     */
    TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    /**
     * Inserts a word into the trie.
     */
    public void insert(String word) {
        HashMap<Character, TrieNode> children = root.children;
        for (int i = 0; i < word.length(); i++) {
            TrieNode next;
            // 如果已有该字母的节点，则转向该节点
            if (children.containsKey(word.charAt(i))) {
                next = children.get(word.charAt(i));
            } else {
                // 如果没有该字母的节点，就新建一个节点
                next = new TrieNode(word.charAt(i));
                children.put(word.charAt(i), next);
            }
            children = next.children;
            if (i == word.length() - 1) {
                next.isLeaf = true;
            }
        }
    }

    /**
     * Returns if the word is in the trie.
     */
    public boolean search(String word) {
        TrieNode res = searchNode(word);
        if (res != null && res.isLeaf) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * Returns if there is any word in the trie that starts with the given prefix.
     */
    public boolean startsWith(String prefix) {
        return searchNode(prefix) != null;
    }

    private TrieNode searchNode(String word) {
        HashMap<Character, TrieNode> children = root.children;
        TrieNode next = null;
        for (int i = 0; i < word.length(); i++) {
            if (children.containsKey(word.charAt(i))) {
                next = children.get(word.charAt(i));
                children = next.children;
            } else {
                return null;
            }
        }
        return next;
    }
}

// Your Trie object will be instantiated and called as such:
// Trie trie = new Trie();
// trie.insert("somestring");
// trie.search("key");