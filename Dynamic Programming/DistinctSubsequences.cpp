int Solution::numDistinct(string A, string B) {
    int n = A.length();
    int m = B.length();
    
    int dp[n+1][m+1];
    for(int i = 0; i <= n; i++) dp[i][m] = 1;
    for(int j = 0; j < m; j++) dp[n][j] = 0;
    
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(A[i] == B[j]) dp[i][j] = dp[i+1][j+1]+dp[i+1][j];
            else dp[i][j] = dp[i+1][j];
        }
    }
    return dp[0][0];
}
