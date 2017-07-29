/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
    struct cmp{
        bool operator () (const Interval &a, const Interval &b) {
            return a.start < b.start || (a.start == b.start && a.end < b.end);
        }
    };
public:
    /** Initialize your data structure here. */
    set<Interval, cmp> st;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        Interval I(val,val);
        if (st.empty()) {
            st.insert(I);
            return;
        }
        auto LB = st.lower_bound(I);
        if (LB != st.begin() && prev(LB)->end >= val-1) {
            I.start = min(I.start, prev(LB)->start);
            I.end = max(I.end, prev(LB)->end);
            st.erase(prev(LB));
        }
        if (LB != st.end() && LB->start <= val+1) {
            I.start = min(I.start, LB->start);
            I.end = max(I.end, LB->end);
            st.erase(LB);
        }
        st.insert(I);
    }
    
    vector<Interval> getIntervals() {
        return vector<Interval>(st.begin(),st.end());
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */