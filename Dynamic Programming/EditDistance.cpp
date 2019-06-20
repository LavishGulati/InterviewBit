int Solution::minDistance(string A, string B) {
    int n = A.size();
    int m = B.size();
    
    int **dp = new int *[n+1];
    for(int i = 0; i <= n; i++){
        dp[i] = new int[m+1];
    }
    
    for(int i = 0; i <= n; i++) dp[i][m] = n-i;
    for(int j = 0; j <= m; j++) dp[n][j] = m-j;
    
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(A[i] == B[j]) dp[i][j] = dp[i+1][j+1];
            else dp[i][j] = dp[i+1][j+1]+1;
            
            dp[i][j] = min(dp[i][j], 1+dp[i+1][j]);
            dp[i][j] = min(dp[i][j], 1+dp[i][j+1]);
        }
    }
    return dp[0][0];
}
