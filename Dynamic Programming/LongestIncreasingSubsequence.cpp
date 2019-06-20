int Solution::lis(const vector<int> &A) {
    int n = A.size();
    int dp[n];
    dp[0] = 1;
    
    for(int i = 1; i < n; i++){
        dp[i] = 1;
        for(int j = i-1; j >= 0; j--){
            if(A[i] > A[j]){
                if(dp[i] == -1) dp[i] = dp[j]+1;
                else dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int answer = 0;
    for(int i = 0; i < n; i++){
        answer = max(answer, dp[i]);
    }
    return answer;
}
