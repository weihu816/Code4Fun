import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

class Interval {
    int start;
    int end;
    int value;
    public Interval(int s, int e, int v) {
        start = s;
        end = e; 
        value = v;
    }
}

public class Solution {
    public static int maxFlow(List<Interval> intervals) {
        // Sort in non-descending order of start time
        Collections.sort(intervals, new Comparator<Interval>() {
            @Override
            public int compare(Interval i1, Interval i2) {
                return i1.start - i2.start;
            }
        });

        int count = 0, max = 0;
        PriorityQueue<Interval> queue = new PriorityQueue<>(new Comparator<Interval>() {
            @Override
            public int compare(Interval i1, Interval i2) {
                return i1.end - i2.end;
            }
        });

        for (int i = 0; i < intervals.size(); i++) {
            Interval interval = intervals.get(i);
            while (!queue.isEmpty() && queue.peek().end < interval.start) {
                count -= queue.poll().value;
            }
            queue.add(interval);
            count += interval.value;
            if (count > max)
                max = count;
        }
        return max;
    }
    
    public static void main(String[] args) {
        Interval i1 = new Interval(0, 10, 100);
        Interval i2 = new Interval(10, 15, 300);
        Interval i3 = new Interval(16, 20, 400);
        Interval i4 = new Interval(5, 15, 200);
        Interval[] array = {i1, i2, i3, i4};
        System.out.println(Solution.maxFlow(Arrays.asList(array)));;
    }
}
