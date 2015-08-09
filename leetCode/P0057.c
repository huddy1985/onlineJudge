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
    vector<Interval> res;
    int min(int a,int b){
        return a<b?a:b;
    }
    int max(int a,int b){
        return a>b?a:b;
    }
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.empty()){
            res.push_back(newInterval);
            return res;
        }
        int i;
        int begin = -1,end = -1;
        int flag = -1;
        for(i=0; i<intervals.size(); i++){
            if(begin == -1){
                if(intervals[i].start > newInterval.end){
                    res.push_back(newInterval);
                    res.push_back(intervals[i]);
                    begin = 0;
                    flag = 0;
                }
                else if(intervals[i].end >= newInterval.start){
                    begin = min(intervals[i].start,newInterval.start);
                    end = max(intervals[i].end,newInterval.end);
                }
                else
                    res.push_back(intervals[i]);
            }else if(flag == -1){
                if(intervals[i].start > newInterval.end){
                    res.push_back(Interval(begin,end));
                    res.push_back(intervals[i]);
                    flag = i-1;
                }
                else
                    end = max(intervals[i].end,newInterval.end);
            }else{
                res.push_back(intervals[i]);
            }
            
        }
        if(flag == -1){
            if(begin == -1){
                res.push_back(newInterval);
            }
            else
                res.push_back(Interval(begin,max(newInterval.end,intervals[i-1].end)));
        }
        return res;
    }
};