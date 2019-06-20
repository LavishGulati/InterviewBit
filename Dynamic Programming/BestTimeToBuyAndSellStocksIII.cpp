typedef long long ll;

int Solution::maxProfit(const vector<int> &A) {
    ll n = A.size();
    if(n < 2) return 0;
    
    ll dp[2][4];
    dp[1][0] = -A[0];
    dp[1][1] = INT_MIN;
    dp[1][2] = INT_MIN;
    dp[1][3] = INT_MIN;
    
    for(ll i = 1; i < n; i++){
        for(int j = 0; j < 4; j++){
            dp[0][j] = dp[1][j];
        }
        
        dp[1][0] = max(ll(-A[i]), dp[0][0]);
        dp[1][1] = max(dp[0][0]+A[i], dp[0][1]);
        dp[1][2] = max(dp[0][1]-A[i], dp[0][2]);
        dp[1][3] = max(dp[0][2]+A[i], dp[0][3]);
    }
    
    ll answer = 0;
    for(ll i = 0; i < 4; i++){
        answer = max(answer, dp[1][i]);
    }
    return answer;
}
