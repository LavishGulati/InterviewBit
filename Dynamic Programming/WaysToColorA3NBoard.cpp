#define MOD 1000000007
typedef long long ll;

int Solution::solve(int A) {
    ll **dp = new ll *[2];
    for(ll i = 0; i < 2; i++){
        dp[i] = new ll[A];
        for(ll j = 0; j < A; j++){
            dp[i][j] = 0;
        }
    }
    
    dp[0][0] = 24;
    dp[1][0] = 12;
    for(ll j = 1; j < A; j++){
        dp[0][j] = (11*dp[0][j-1])%MOD;
        dp[0][j] = (dp[0][j]+(10*dp[1][j-1])%MOD)%MOD;
        dp[1][j] = (5*dp[0][j-1])%MOD;
        dp[1][j] = (dp[1][j]+(7*dp[1][j-1])%MOD)%MOD;
    }
    return (dp[0][A-1]+dp[1][A-1])%MOD;
}
