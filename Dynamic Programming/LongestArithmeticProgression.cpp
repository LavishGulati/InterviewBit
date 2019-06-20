int Solution::solve(const vector<int> &A) {
    map<int, int> m;
    int n = A.size();
    if(n < 3) return n;
    
    int dp[n][n], diff;
    int MaxLength = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            dp[i][j] = 2;
            diff = A[j]-A[i];
            if(m.find(A[i]-diff) != m.end()){
                dp[i][j] = max(dp[m[A[i]-diff]][i]+1, dp[i][j]);
            }
            MaxLength = max(MaxLength, dp[i][j]);
        }
        m[A[i]] = i;
    }
    
    return MaxLength;
}
