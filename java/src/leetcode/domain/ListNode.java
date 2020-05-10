package leetcode.domain;

/**
 * author：baixiaoling
 * date: 2017/12/14
 * <p>
 * description:
 */
public class ListNode {
    public int val;
    public ListNode next;

    public ListNode(int x) {
        val = x;
    }

    public String toString() {
        return val + "->" + next;
    }
}
