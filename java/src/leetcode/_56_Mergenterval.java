package leetcode;

import leetcode.domain.Interval;

import java.util.ArrayList;
import java.util.List;

/**
 * author：baixiaoling
 * date: 2017/12/22
 * <p>
 * description:
 * Given a collection of intervals, merge all overlapping intervals.
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 */
public class _56_Mergenterval {
    /*
    复用插入操作：_54
     */

    public List<Interval> merge(List<Interval> intervals) {
        List<Interval> result = new ArrayList<>();
        if (intervals == null || intervals.size() == 0) return result;
        for (Interval interval : intervals) {
            result = insert(result, interval);

        }
        return result;

    }

    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {

        List<Interval> result = new ArrayList<>();
        for (Interval interval : intervals) {

            if (interval.end < newInterval.start) {
                result.add(interval);
            } else if (interval.start > newInterval.end) {
                result.add(newInterval);
                newInterval = interval;
            } else {
                newInterval = new Interval(Math.min(interval.start, newInterval.start), Math.max(interval.end, newInterval.end));
            }

        }
        result.add(newInterval);

        return result;
    }

    public static void main(String[] args) {
        _56_Mergenterval object = new _56_Mergenterval();
        List<Interval> lists = new ArrayList<>();
        lists.add(new Interval(1, 3));
        lists.add(new Interval(2, 6));
        lists.add(new Interval(8, 10));
        lists.add(new Interval(15, 18));
        System.out.println(object.merge(lists));
    }
}
