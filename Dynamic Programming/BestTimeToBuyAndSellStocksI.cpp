int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    if(n == 0) return 0;
    
    int dp[n][2];
    dp[0][0] = -A[0];
    dp[0][1] = INT_MIN;
    for(int i = 1; i < n; i++){
        dp[i][0] = max(dp[i-1][0], -A[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]+A[i]);
    }
    return max(dp[n-1][0], max(dp[n-1][1], 0));
}
