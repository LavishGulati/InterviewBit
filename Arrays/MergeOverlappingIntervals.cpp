/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#define all(x) x.begin(), x.end()
#define pb push_back

bool compare(Interval a, Interval b){
    if(a.start < b.start) return true;
    else if(a.start == b.start) return a.end < b.end;
    else return false;
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    int n = A.size();
    sort(all(A), compare);
    
    vector<Interval> output;
    bool keep[n];
    for(int i = 0; i < n; i++) keep[i] = true;
    int StartTime, EndTime;
    int NextI = 1;
    for(int i = 0; i < A.size()-1; i++){
        if(NextI < A.size() && A[i].end >= A[NextI].start){
            StartTime = min(A[i].start, A[NextI].start);
            EndTime = max(A[i].end, A[NextI].end);
            A[i].start = StartTime;
            A[i].end = EndTime;
            keep[NextI] = false;
            // A.erase(A.begin()+i+1);
            i--;
        }
        NextI++;
    }
    for(int i = 0; i < n; i++){
        if(keep[i]) output.pb(A[i]);
    }
    return output;
}

