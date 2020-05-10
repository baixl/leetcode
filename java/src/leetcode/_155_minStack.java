package leetcode;

import java.util.*;

/**
 * author：baixiaoling
 * date: 2018/1/8
 * <p>
 * description:
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * <p>
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * Example:
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 解题思路：http://blog.csdn.net/linhuanmars/article/details/41008731
 */
public class _155_minStack {
    /**
     * initialize your data structure here.
     */
    Stack<Integer> stack;// 存放栈数据
    Stack<Integer> minstack; //存放最小值

    public _155_minStack() {
        stack = new Stack<>();
        minstack = new Stack<>();
    }

    public void push(int x) {
        stack.push(x);
        if (minstack.isEmpty()) {
            minstack.push(x);
        } else {
            minstack.push(Math.min(x, minstack.peek()));
        }
    }

    public void pop() {
        if (stack.isEmpty()) {
            return;
        } else {
            stack.pop();
            minstack.pop();
        }


    }

    public int top() {
        if (!stack.isEmpty()) {
            return stack.peek();
        }
        return 0;
    }

    public int getMin() {
        if (!minstack.isEmpty()) {
            return minstack.peek();
        } else {
            return 0;
        }
    }

    public static void main(String[] args) {

    }

}
