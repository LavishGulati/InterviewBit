int Solution::isMatch(const string A, const string B) {
    int n = A.length();
    int m = B.length();
    
    int dp[m+1];
    int helper[m+1];
    
    dp[m] = true;
    for(int j = m-1; j >= 0; j--){
        if(j < m-1 && B[j+1] == '*'){
            dp[j] = dp[j+2];
        }
        else dp[j] = false;
    }
    
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j <= m; j++){
            helper[j] = dp[j];
        }
        
        dp[m] = false;
        for(int j = m-1; j >= 0; j--){
            if(B[j] == '*') dp[j] = false;
            else if(j < m-1 && B[j+1] == '*'){
                if(B[j] == '.'){
                    dp[j] = helper[j] || dp[j+2];
                }
                else if(A[i] != B[j]){
                    dp[j] = dp[j+2];
                }
                else{
                    dp[j] = helper[j] || dp[j+2];
                }
            }
            else if(B[j] == '.'){
                dp[j] = helper[j+1];
            }
            else if(B[j] == A[i]){
                dp[j] = helper[j+1];
            }
            else dp[j] = false;
            
        }
    }
    
    return dp[0] ? 1 : 0;
}
