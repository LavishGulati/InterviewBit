#define all(x) x.begin(), x.end()

int Solution::solve(vector<int> &A) {
    sort(all(A));
    int n = A.size();
    for(int i = 0; i < n; i++){
        int j = i+1;
        while(j < n && A[j] == A[i]) j++;
        i = j-1;
        if(n-i-1 == A[i]) return 1;
    }
    
    return -1;
}

