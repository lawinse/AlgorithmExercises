/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool cmp(Interval &a, Interval &b){
        return a.start == b.start ? a.end<b.end : a.start<b.start;
    }
class Solution {
public:

    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int curS, curE;
        int n = intervals.size();
        vector<Interval> ret;
        if (n == 0) return ret;
        if(n == 1){ret.push_back(intervals[0]);return ret;}
        curS = intervals[0].start,curE = intervals[0].end;
        int id = 0;
        while(id < n-1){
            id++;
            if (intervals[id].start <= curE){
                curE = max(curE,intervals[id].end);
            }else{
                ret.push_back(Interval(curS,curE));
                curS = intervals[id].start;
                curE = intervals[id].end;
            }
        }
        ret.push_back(Interval(curS,curE));
        return ret;
    }
};