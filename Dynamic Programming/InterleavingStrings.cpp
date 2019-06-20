int Solution::isInterleave(string A, string B, string C) {
    if(C.length() != A.length()+B.length()) return false;
    
    int n = A.length();
    int m = B.length();
    bool dp[n+1][m+1];
    dp[n][m] = true;
    
    for(int i = n-1; i >= 0; i--){
        if(A[i] == C[m+i]) dp[i][m] = dp[i+1][m];
        else dp[i][m] = false;
    }
    
    for(int j = m-1; j >= 0; j--){
        if(B[j] == C[n+j]) dp[n][j] = dp[n][j+1];
        else dp[n][j] = false;
    }
    
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(A[i] != C[i+j] && B[j] != C[i+j]){
                dp[i][j] = false;
            }
            else if(A[i] != C[i+j]){
                dp[i][j] = dp[i][j+1];
            }
            else if(B[j] != C[i+j]){
                dp[i][j] = dp[i+1][j];
            }
            else{
                dp[i][j] = dp[i+1][j] || dp[i][j+1];
            }
        }
    }
    
    return dp[0][0] ? 1 : 0;
}
