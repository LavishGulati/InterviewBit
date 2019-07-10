int Solution::solve(const vector<int> &A) {
    int n = A.size();
    int sum = 0;
    for(int i = 0; i < n; i++) sum += A[i];
    
    sum /= 2;
    int dp[n+1][sum+1];
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) dp[i][0] = 0;
    for(int j = 1; j <= sum; j++) dp[0][j] = -1;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            dp[i][j] = dp[i-1][j];
            if(A[i-1] <= j && dp[i-1][j-A[i-1]] != -1){
                if(dp[i][j] == -1) dp[i][j] = dp[i-1][j-A[i-1]]+1;
                else dp[i][j] = min(dp[i][j], dp[i-1][j-A[i-1]]+1);
            }
        }
    }
    
    for(int j = sum; j >= 0; j--){
        if(dp[n][j] != -1) return dp[n][j];
    }
}
