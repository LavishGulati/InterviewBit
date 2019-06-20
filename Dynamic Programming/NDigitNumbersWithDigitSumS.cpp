typedef long long ll;
#define MOD 1000000007

int Solution::solve(int A, int B) {
    ll **dp = new ll *[A+1];
    for(ll i = 0; i <= A; i++){
        dp[i] = new ll[B+1];
        for(ll j = 0; j <= B; j++){
            dp[i][j] = 0;
        }
    }
    
    for(ll j = 0; j <= min(9, B); j++) dp[1][j] = 1;
    for(ll i = 2; i <= A-1; i++){
        for(ll j = 0; j <= B; j++){
            dp[i][j] = 0;
            for(ll k = 0; k <= 9; k++){
                if(j-k >= 0) dp[i][j] = (dp[i][j]+dp[i-1][j-k])%MOD;
            }
        }
    }
    for(ll j = 0; j <= B; j++){
        dp[A][j] = 0;
        for(ll k = 1; k <= 9; k++){
            if(j-k >= 0) dp[A][j] = (dp[A][j]+dp[A-1][j-k])%MOD;
        }
    }
    
    return dp[A][B];
}
