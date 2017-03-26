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
    bool static cmp(const Interval &lhs, const Interval &rhs) {
        return (lhs.start < rhs.start) ||
            (lhs.start == rhs.start && lhs.end < rhs.end);
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        std::sort(intervals.begin(), intervals.end(), cmp);
        if (intervals.empty()) 
            return result;
        int start = intervals[0].start, end = intervals[0].end;
        for (int i = 1; i < intervals.size(); ++i) {
            auto &interval = intervals[i];
            if (interval.start <= end) {
                end = max(interval.end, end);
            }
            else {
                result.push_back(Interval(start, end));
                start = interval.start;
                end = interval.end;
            }
        }
        result.push_back(Interval(start, end));
        return result;
    }
};
