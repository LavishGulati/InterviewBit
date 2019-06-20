int Solution::maxcoin(vector<int> &A) {
    int n = A.size();
    int dp[n][n];
    int i, j;
    i = 0; j = 1;
    while(j < n){
        dp[i][j] = max(A[i], A[j]);
        i++; j++;
    }
    
    int col = 3, x, y;
    while(col < n){
        i = 0; j = col;
        while(j < n){
            x = A[i]+min(dp[i+2][j], dp[i+1][j-1]);
            y = A[j]+min(dp[i+1][j-1], dp[i][j-2]);
            dp[i][j] = max(x, y);
            i++; j++;
        }
        col += 2;
    }
    
    return dp[0][n-1];
}
