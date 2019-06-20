int Solution::numDecodings(string A) {
    int n = A.length();
    int dp[n];
    if(A[0] == '0') dp[0] = 0;
    else dp[0] = 1;
    
    int x;
    for(int i = 1; i < n; i++){
        if(A[i] == '0') dp[i] = 0;
        else dp[i] = dp[i-1];
        
        x = (A[i-1]-'0')*10 + (A[i]-'0'); 
        if(x <= 26 && x >= 10){
            if(i > 1) dp[i] += dp[i-2];
            else dp[i] += 1;
        }

    }
    
    return dp[n-1];
}
