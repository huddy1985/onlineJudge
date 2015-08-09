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
private:
    int max(int a,int b){
        return a>b?a:b;
    }
static bool greater(Interval a,Interval b){
        return a.start<b.start;
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(),intervals.end(),greater);
        int i = 0,s = intervals[0].start,t = intervals[0].end;
        vector<Interval> res;
        for(i=1; i<intervals.size(); i++){
            if(intervals[i].start <= t)
                t = max(t,intervals[i].end);
            else{
                res.push_back(Interval(s,t));
                s = intervals[i].start;
                t = intervals[i].end;
            }
        }
        res.push_back(Interval(s,t));
        return res;
    }
};