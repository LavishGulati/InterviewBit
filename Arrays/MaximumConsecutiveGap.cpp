typedef pair<int, int> pii;
#define f first
#define s second

int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    if(n == 1) return 0;
    
    int MinEl = INT_MAX, MaxEl = INT_MIN;
    for(int i = 0; i < n; i++){
        MinEl = min(MinEl, A[i]);
        MaxEl = max(MaxEl, A[i]);
    }
    
    double gap = (double(MaxEl)-double(MinEl))/(double(n-1));
    if(gap == 0) return 0;
    
    pii buckets[n-1];
    for(int i = 0; i < n-1; i++){
        buckets[i].f = INT_MAX;
        buckets[i].s = INT_MIN;
    }
    
    int id;
    for(int i = 0; i < n; i++){
        id = int(floor((double(A[i])-double(MinEl))/gap));
        if(A[i] == MaxEl) id--;
        buckets[id].f = min(buckets[id].f, A[i]);
        buckets[id].s = max(buckets[id].s, A[i]);
    }
    
    int answer = int(gap);
    for(int i = 1; i < n-1; i++){
        if(buckets[i].f != INT_MAX){
            id = i-1;
            while(id > 0 && buckets[id].s == INT_MIN) id--;
            answer = max(answer, buckets[i].f-buckets[id].s);
        }
    }
    
    return answer;
}

