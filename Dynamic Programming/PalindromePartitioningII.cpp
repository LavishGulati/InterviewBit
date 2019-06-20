int Solution::minCut(string A) {
    int n = A.length();
    int dp[n];
    dp[n-1] = 0;
    
    bool IsPalindrome[n][n+1];
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n; j++){
            IsPalindrome[i][j] = false;
        }
    }
    
    bool ans;
    for(int i = 0; i < n; i++){
        ans = true;
        for(int j = 1; i-j/2 >= 0 && i+j/2 < n; j += 2){
            if(ans){
                if(A[i-j/2] == A[i+j/2]) IsPalindrome[i-j/2][j] = true;
                else{
                    ans = false;
                    IsPalindrome[i-j/2][j] = false;
                }
            }
            else IsPalindrome[i-j/2][j] = false;
        }
        
        ans = true;
        for(int j = 2; i-j/2+1 >= 0 && i+j/2 < n; j += 2){
            if(ans){
                if(A[i-j/2+1] == A[i+j/2]) IsPalindrome[i-j/2+1][j] = true;
                else{
                    ans = false;
                    IsPalindrome[i-j/2+1][j] = false;
                }
            }
            else IsPalindrome[i-j/2+1][j] = false;
        }
    }
    
    for(int i = n-2; i >= 0; i--){
        if(IsPalindrome[i][n-i]){
            dp[i] = 0;
        }
        else{
            dp[i] = dp[i+1]+1;
            for(int j = 2; j < n-i; j++){
                if(IsPalindrome[i][j]){
                    dp[i] = min(dp[i], 1+dp[i+j]);
                }
            }
        }
    }
    return dp[0];
}s
