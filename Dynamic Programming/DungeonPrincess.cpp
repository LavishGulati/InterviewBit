int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int dp[n][m];
    
    if(A[n-1][m-1] >= 0) dp[n-1][m-1] = 1;
    else dp[n-1][m-1] = abs(A[n-1][m-1])+1;
    
    for(int i = n-2; i >= 0; i--){
        dp[i][m-1] = max(1, dp[i+1][m-1]-A[i][m-1]);
    }
    
    for(int j = m-2; j >= 0; j--){
        dp[n-1][j] = max(1, dp[n-1][j+1]-A[n-1][j]);
    }
    
    int x, y;
    for(int i = n-2; i >= 0; i--){
        for(int j = m-2; j >= 0; j--){
            x = max(1, dp[i+1][j]-A[i][j]);
            y = max(1, dp[i][j+1]-A[i][j]);
            dp[i][j] = min(x, y);
        }
    }
    
    return dp[0][0];
}
