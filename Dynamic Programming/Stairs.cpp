int Solution::climbStairs(int A) {
    int dp[A];
    dp[0] = 1;
    for(int i = 1; i < A; i++){
        if(i == 1){
            dp[i] = 1+dp[i-1];
        }
        else{
            dp[i] = dp[i-1]+dp[i-2];
        }
    }
    
    return dp[A-1];
}
