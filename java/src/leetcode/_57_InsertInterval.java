package leetcode;

import leetcode.domain.Interval;

import java.util.ArrayList;
import java.util.List;

/**
 * author：baixiaoling
 * date: 2017/12/22
 * <p>
 * description:
 */
public class _57_InsertInterval {

    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        List<Interval> result = new ArrayList<>();

        boolean inserted = false;
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
        _57_InsertInterval object = new _57_InsertInterval();
        List<Interval> lists = new ArrayList<>();
        lists.add(new Interval(1, 2));
        lists.add(new Interval(3, 5));
        lists.add(new Interval(6, 7));
        lists.add(new Interval(8, 10));
        lists.add(new Interval(12, 16));
        System.out.println(object.insert(lists, new Interval(4, 9)));
    }
}
