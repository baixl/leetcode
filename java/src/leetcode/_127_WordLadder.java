package leetcode;

import java.util.*;

/**
 * author：baixiaoling
 * date: 2017/12/30
 * <p>
 * description:
 * Given two words (beginWord and endWord), and a dictionary's word list,
 * find the length of shortest transformation sequence from beginWord to endWord, such that:
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
 * For example,
 * <p>
 * Given:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 * <p>
 * Note:
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * <p>
 * 解题思路：
 * 广度优先搜索
 * 1  借助一个队列保存列表字符串
 * 2 借助一个hashset保存访问过的元素
 * <p>
 * 这道题类似图的广度优先搜索两个单词相差一个单词变化时，对应两个单词在图中节点有边相连
 * <p>
 * 求两个节点的最短路径
 * <p>
 * 参考：https://www.jiuzhang.com/solution/word-ladder/
 */
public class _127_WordLadder {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (beginWord == null || endWord == null || beginWord.length() == 0 ||
                endWord.length() == 0 || beginWord.length() != endWord.length())
            return 0;
        if (beginWord.equals(endWord)) {
            return 1;
        }

        Set<String> dict = new HashSet<>();
        Queue<String> queue = new LinkedList<>();
        HashSet<String> hashSet = new HashSet<>();
        for (String s : wordList) {
            dict.add(s);
        }

        queue.offer(beginWord);
        hashSet.add(beginWord);

        int length = 1;
        while (!queue.isEmpty()) {
            length++; // 更深一层
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String word = queue.poll();
                for (String nextWord : getNextWords(word, dict)) {
                    if (hashSet.contains(nextWord)) {
                        continue;
                    }
                    if (nextWord.equals(endWord)) {
                        return length;
                    }
                    hashSet.add(nextWord);
                    queue.offer(nextWord);
                }
            }
        }
        return 0;
    }

    private ArrayList<String> getNextWords(String word, Set<String> dict) {
        ArrayList<String> nextWords = new ArrayList<>();
        for (char c = 'a'; c <= 'z'; c++) {
            for (int i = 0; i < word.length(); i++) {
                if (c == word.charAt(i)) {
                    continue;
                }
                char[] chars = word.toCharArray();
                chars[i] = c;
                String nextWord = new String(chars);
                if (dict.contains(nextWord)) {
                    nextWords.add(nextWord);
                }
            }
        }
        return nextWords;
    }

    public static void main(String[] args) {
        _127_WordLadder object = new _127_WordLadder();
        List<String> wordList = new ArrayList<>();
        wordList.add("hot");
        wordList.add("dot");
        wordList.add("dog");
        wordList.add("lot");
        wordList.add("log");
        System.out.println(object.ladderLength("hit", "cog", wordList));
    }
}
