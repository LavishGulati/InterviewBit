int Solution::arrange(string A, int B) {
    int n = A.length();
    if(B > n || B == 0) return -1;
    
    int dp[n][B+1];
    int black = 0;
    int white = 0;
    for(int i = n-1; i >= 0; i--){
        if(A[i] == 'B') black++;
        else white++;
        dp[i][1] = black*white;
    }
    
    for(int j = 2; j <= B; j++){
        for(int i = n-1; i >= 0; i--){
            if(n-i < j){
                dp[i][j] = -1;
                continue;
            }
            
            black = white = 0;
            dp[i][j] = INT_MAX;
            for(int k = i; k < n-1; k++){
                if(A[k] == 'B') black++;
                else white++;
                
                if(dp[k+1][j-1] != -1){
                    dp[i][j] = min(dp[i][j], white*black+dp[k+1][j-1]);
                }
            }
        }
    }
    
    return dp[0][B];
}
