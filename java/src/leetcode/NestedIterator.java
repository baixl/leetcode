package leetcode;

import java.util.*;

/**
 * author：baixiaoling
 * date: 2018/1/15
 * <p>
 * description:
 * Given a nested list of integers, implement an iterator to flatten it.
 * <p>
 * Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 * <p>
 * Example 1:
 * Given the list [[1,1],2,[1,1]],
 * <p>
 * By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
 * <p>
 * Example 2:
 * Given the list [1,[4,[6]]],
 * <p>
 * By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
 * <p>
 * 解题思路：给定一个嵌套列表，实现一个迭代器将其展开
 * 每个元素要么是整数，要么是列表
 * 解题思路：在构造函数中递归构造一个队列，迭代
 */

interface NestedInteger {

    // @return true if this NestedInteger holds a single integer, rather than a nested list.
    public boolean isInteger();

    // @return the single integer that this NestedInteger holds, if it holds a single integer
    // Return null if this NestedInteger holds a nested list
    public Integer getInteger();

    // @return the nested list that this NestedInteger holds, if it holds a nested list
    // Return null if this NestedInteger holds a single integer
    public List<NestedInteger> getList();
}

public class NestedIterator implements Iterator<Integer> {

    Queue<NestedInteger> stack = new LinkedList<>();

    public NestedIterator(List<NestedInteger> nestedList) {
        for (int i = 0; i < nestedList.size(); i++) {
            handle(stack, nestedList.get(i));
        }

    }

    @Override
    public boolean hasNext() {
        while (!stack.isEmpty()) {
            return true;
        }
        return false;
    }

    @Override
    public Integer next() {
        return stack.poll().getInteger();
//        NestedInteger nestedInteger = queue.poll();
//        return nestedInteger.getInteger();
    }
//
//    public static void main(String[] args) {
//        NestedIterator object =  new NestedIterator();
//
//    }

    private void handle(Queue<NestedInteger> queue, NestedInteger nestedInteger) {
        if (nestedInteger.isInteger()) {
            queue.offer(nestedInteger);
        } else {
            for (int i = 0; i < nestedInteger.getList().size(); i++) {
                handle(queue, nestedInteger.getList().get(i));
            }
        }
    }
}
