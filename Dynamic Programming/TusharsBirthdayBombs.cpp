#define pb push_back

vector<int> Solution::solve(int A, vector<int> &B) {
    int n = B.size();
    
    int MinEl = INT_MAX;
    for(int i = 0; i < n; i++){
        MinEl = min(MinEl, B[i]);
    }
    
    int answer = A/MinEl;
    int total = answer*MinEl;
    
    vector<int> output;
    for(int i = 0; i < n; i++){
        if(output.size() == answer) break;
        if(A-total >= B[i]-MinEl){
            output.pb(i);
            total += B[i]-MinEl;
            i--;
        }
    }
    
    return output;
}
