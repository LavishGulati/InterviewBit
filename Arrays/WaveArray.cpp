#define pb push_back
#define all(x) x.begin(), x.end()

vector<int> Solution::wave(vector<int> &A) {
    int n = A.size();
    sort(all(A));
    vector<int> output;
    for(int i = 0; i < n; i += 2){
        if(i+1 < n) output.pb(A[i+1]);
        output.pb(A[i]);
    }
    return output;
}

