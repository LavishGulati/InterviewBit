int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int n = A.size();
    int o = B.size();
    
    int m = 0;
    for(int i = 0; i < n; i++){
        m = max(m, A[i]);
    }
    
    int dp[m+1];
    for(int i = 0; i <= m; i++){
        dp[i] = INT_MAX;
    }
    for(int i = 0; i < o; i++){
        if(B[i] > m) continue;
        if(dp[B[i]] == INT_MAX) dp[B[i]] = C[i];
        else dp[B[i]] = min(dp[B[i]], C[i]);
    }
    
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < o; j++){
            if(i-B[j] >= 0 && dp[i-B[j]] < INT_MAX){
                dp[i] = min(dp[i], C[j]+dp[i-B[j]]);
            }
        }
    }
    
    int answer = 0;
    for(int i = 0; i < n; i++){
        answer += dp[A[i]];
    }
    return answer;
}
