/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
#define pb push_back
 
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    int n = intervals.size();
    
    
    int PushId = -1;
    int NewStartTime = min(newInterval.start, newInterval.end);
    int NewEndTime = max(newInterval.start, newInterval.end);
    bool MergeIntervals[n];
    for(int i = 0; i < n; i++){
        MergeIntervals[i] = false;
    }
    
    for(int i = 0; i < n; i++){
        if((NewStartTime <= intervals[i].end && NewStartTime >= intervals[i].start) || (NewEndTime <= intervals[i].end && NewEndTime >= intervals[i].start) || (intervals[i].start >= NewStartTime && intervals[i].end <= NewEndTime)){
            NewStartTime = min(intervals[i].start, NewStartTime);
            NewEndTime = max(intervals[i].end, NewEndTime);
            MergeIntervals[i] = true;
            if(PushId == -1) PushId = i;
        }
    }
    
    vector<Interval> output;
    if(n == 0){
        output.pb(Interval(NewStartTime, NewEndTime));
        return output;
    }
    bool IsIncluded = false;
    if(NewEndTime < intervals[0].start){
        output.pb(Interval(NewStartTime, NewEndTime));
        IsIncluded = true;
    }
    for(int i = 0; i < n; i++){
        if(MergeIntervals[i] && !IsIncluded){
            output.pb(Interval(NewStartTime, NewEndTime));
            IsIncluded = true;
        }
        else if(NewStartTime < intervals[i].start && NewStartTime > intervals[i-1].end && !IsIncluded){
            output.pb(Interval(NewStartTime, NewEndTime));
            IsIncluded = true;
            output.pb(intervals[i]);
        }
        else if(!MergeIntervals[i]){
            output.pb(intervals[i]);
        }
    }
    
    if(!IsIncluded) output.pb(Interval(NewStartTime, NewEndTime));
    return output;
}

