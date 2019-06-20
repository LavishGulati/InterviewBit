typedef long long ll;
#define MOD 1000000007

int Solution::chordCnt(int A) {
    ll dp[A+1];
    dp[0] = 1;
    dp[1] = 1;
    ll x;
    for(ll i = 2; i <= A; i++){
        dp[i] = 0;
        for(ll j = 0; j < i; j++){
            x = (dp[j]*dp[i-j-1])%MOD;
            dp[i] = (dp[i]+x)%MOD;
        }
    }
    
    return dp[A];
}
