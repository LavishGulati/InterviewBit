int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int dp[n][m];
    
    if(A[0][0] == 0) dp[0][0] = 1;
    else dp[0][0] = 0;
    
    for(int i = 1; i < n; i++){
        if(A[i][0] == 1) dp[i][0] = 0;
        else dp[i][0] = dp[i-1][0];
    }
    
    for(int j = 1; j < m; j++){
        if(A[0][j] == 1) dp[0][j] = 0;
        else dp[0][j] = dp[0][j-1];
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(A[i][j] == 1) dp[i][j] = 0;
            else{
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    
    return dp[n-1][m-1];
}
