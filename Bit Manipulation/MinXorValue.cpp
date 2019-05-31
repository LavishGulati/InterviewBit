#define all(x) x.begin(), x.end()

int Solution::findMinXor(vector<int> &A) {
    sort(all(A));
    int n = A.size();
    
    int MinXor = INT_MAX, temp;
    for(int i = 1; i < n; i++){
        MinXor = min(MinXor, A[i]^A[i-1]);
    }
    
    return MinXor;
}

