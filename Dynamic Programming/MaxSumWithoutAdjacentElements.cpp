int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    
    int dp[2][n];
    dp[0][0] = 0;
    dp[1][0] = max(A[0][0], A[1][0]);
    if(n > 1){
        dp[0][1] = max(dp[0][0], dp[1][0]);
        dp[1][1] = max(A[0][1], A[1][1]);
    }
    
    for(int i = 2; i < n; i++){
        dp[0][i] = max(dp[1][i-1], dp[0][i-1]);
        dp[1][i] = max(dp[0][i-1], max(dp[1][i-2], dp[0][i-2]))+max(A[0][i], A[1][i]);
    }
    
    return max(dp[0][n-1], dp[1][n-1]);
}
