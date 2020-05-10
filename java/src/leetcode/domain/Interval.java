package leetcode.domain;

/**
 * author：baixiaoling
 * date: 2017/12/22
 * <p>
 * description:
 */
public class Interval {
    public int start;
    public int end;

    public Interval() {
        start = 0;
        end = 0;
    }


    public Interval(int s, int e) {
        start = s;
        end = e;
    }

    @Override
    public String toString() {
        return "[" + start + " , " + end + "]";
    }
}
