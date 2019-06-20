int Solution::minPathSum(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int dp[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dp[i][j] = A[i][j];
        }
    }
    
    int x;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0) continue;
            x = INT_MAX;
            if(i > 0) x = min(x, dp[i-1][j]+A[i][j]);
            if(j > 0) x = min(x, dp[i][j-1]+A[i][j]);
            dp[i][j] = x;
        }
    }
    return dp[n-1][m-1];
}
