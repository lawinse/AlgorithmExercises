/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int len = intervals.size();
        if (len == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        for (int i=0; i<len; ++i) {
            if (newInterval.end<intervals[i].start) {
                intervals.insert(intervals.begin()+i,newInterval);
                return intervals;
            } else if (newInterval.start > intervals[i].end) continue;
            else {
                int j = i;
                while(i<len && newInterval.end >= intervals[i].start) ++i;
                intervals[j].start = min(intervals[j].start, newInterval.start);
                intervals[j].end = max(intervals[i-1].end, newInterval.end);
                while(i<len) {
                    intervals[++j] = intervals[i++];
                }
                intervals.resize(j+1);
                return intervals;
            }
            
        }
        intervals.push_back(newInterval);
        return intervals;
        
    }
};